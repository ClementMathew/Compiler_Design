%{
#include<stdio.h>
%}
%token NUMBER
%start S
%%
S :E{printf("Expression value: %d",$1);}
;
E   :E'+'T{$$ = $1+$3;printf("+ sign\n");}
    |E'-'T{$$ = $1-$3;printf("- sign\n");}
    |T
;
T   :T'*'F{$$ = $1*$3;printf("* sign\n");}
    |T'/'F{$$ = $1/$3;printf("/ sign\n");}
    |F
;
F   :NUMBER{$$ = $1;printf("NUmber detected\n");}
    |'('E')'{$$ = $2;}
%%

int main()
{
    printf("Enter the expression: \n");
    yyparse();
    return 0;
}
int yyerror(char* msg)
{
    printf("Invalid experssion");
    return 0;
}
int yywrap()
{
    return 1;
}