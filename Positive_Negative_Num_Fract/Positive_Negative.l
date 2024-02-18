%{
#include<stdio.h>
int posn = 0, negn = 0, posf = 0, negf = 0;    
%}

%%
\+[0-9]+\/[1-9][0-9]* {posf++;}
\-[0-9]+\/[1-9][0-9]* {negf++;}
\+[1-9][0-9]* {posn++;}
\-[1-9][0-9]* {negn++;}
%%

int main()
{
    yyin  = fopen("input.txt","r");
    yylex();
    printf("The number of positive fraction : %d\n",posf);
    printf("The number of negative fraction : %d\n",negf);
    printf("The number of positive integers : %d\n",posn);
    printf("The number of negative integers : %d\n",negn);
    return 0;
}
int yywrap()
{
    return 1;
}