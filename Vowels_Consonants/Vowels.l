%{
#include<stdio.h>
int vow_count=0;
int const_count =0;
%}

%%
[aeiouAEIOU] {vow_count++;}
. {const_count++;}
[\n] {printf("Number of vowels are: %d\n", vow_count);printf("Number of consonants are: %d\n", const_count);}
%%

int main()
{
printf("Enter the string :");
yylex();
return 0;
} 

int yywrap(){return 1;}