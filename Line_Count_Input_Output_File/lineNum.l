%{
#include<stdio.h>
int lc = 0, cc = 0, wc = 0;
%}

%%
[ ] {wc++;}
[\n] {lc++; wc++;}
. {cc++;}
%%

int main()
{
    printf("Enter the string : ");
    yyin = fopen("input.txt","r");
    yyout = fopen("result.txt", "w");
    yylex();
    printf("Lines = %d \nWords = %d \nCharacters = %d \n",lc,wc,cc);
    fprintf(yyout,"Lines = %d \nWords = %d \nCharacters = %d \n",lc,wc,cc);
    return 0;
}

int yywrap()
{
    return 1;
}