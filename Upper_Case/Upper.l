%{
#include <stdio.h>
int cnt  = 0;
%}

%%
abc {printf("ABC");}
. {printf("%s",yytext);}
%%

int main()
{
yyin = fopen("abc.txt","r");
yylex();
return 0;
}
int yywrap()
{
return 1;
}