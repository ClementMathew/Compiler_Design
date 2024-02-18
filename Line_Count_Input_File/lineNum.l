
%{
#include<stdio.h>
int wc=1,lc=1,cc=0;
%}

%%
[ ] { wc++;}
[\n] { lc++;wc++;}
. { cc++;}
%%

int yywrap(){ return 1; }

int main(){
yyin = fopen("input.txt","r");
yylex();
printf("Number of lines : %d\n",lc);
printf("Number of words : %d\n",wc);
printf("Number of characters : %d\n",cc);

return 0;
}

