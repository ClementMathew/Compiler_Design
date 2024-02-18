%{
    #include<stdio.h>
    int flag = 0;
%}

%%
"//".* {}
"/*" {flag = 1;}
"*/" {flag = 0;}
. {if(flag == 0){fprintf(yyout,"%s",yytext);}}
%%

void main()
{
    yyin = fopen("input.txt","r");
    yyout = fopen("result.txt","w");
    yylex();
}

int yywrap()
{
    return 1;
}