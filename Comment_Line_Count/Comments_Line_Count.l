%{
#include<stdio.h>
int flag=0,lines=0;
%}

%%
"//".* { lines++;}
"/*" { flag=1;lines++;}
"*/" { flag=0;}
[\n] { if(flag==1){lines++;}else{fprintf(yyout,"%s",yytext);}}
. { 
if(flag==0)
{
fprintf(yyout,"%s",yytext);
}
}
%%
 
int main()
{
  yyin=fopen("in.txt","r");
  yyout=fopen("out.txt","w");
  yylex();
  printf("no of comment lines = %d\n",lines);
  return 0;
}

int yywrap()
{
  return 1;
}