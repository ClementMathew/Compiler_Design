%{
#include<stdio.h>
int lc = 0, cc = 0, wc = 0;
%}

%%
[ ] {wc++;}
[\n] {lc++; wc++; printf("Lines = %d \nWords = %d \nCharacters = %d \n",lc,wc,cc);lc = 0;cc = 0; wc=0;}
. {cc++;}
%%

int main()
{
    printf("Enter the string : ");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}