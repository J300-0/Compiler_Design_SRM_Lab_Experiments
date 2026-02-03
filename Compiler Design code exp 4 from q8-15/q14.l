%{
#include <stdio.h>
%}

%%
"+"|"-"|"*"|"/"     { printf("%s is an Arithmetic Operator\n", yytext); }
">"|"<"|">="|"<="   { printf("%s is a Relational Operator\n", yytext); }
"="                 { printf("%s is an Assignment Operator\n", yytext); }
[a-zA-Z0-9]+        { printf("%s is NOT an operator\n", yytext); }
.|\n                ;
%%

int main() {
    printf("Enter operator: ");
    yylex();
    return 0;
}
int yywrap() { return 1; }