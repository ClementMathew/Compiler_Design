%{
#include"Cal.tab.h"
extern yylval;    
%}
%%
[0-9] {yylval = atoi(yytext);printf("Got a number:%d\n",yylval);return NUMBER;}
[\t] {printf("Skiped whitespaces\n");}
\n {printf("Reached end of line\n");return 0;}
. {printf("Other data:%s\n",yytext);return yytext[0];}
%%