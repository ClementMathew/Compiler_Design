%{
#include<stdio.h>
int line_count = 1;
%}

%%
[\n] {printf("\nLine number: %d ",line_count);line_count++;}
. {printf("%c",yytext[0]);}
%%

int main()
{
    yyin = fopen("text.txt","r");
    yylex();
    return 0;
}
int yywrap()
{
    return 1;
}