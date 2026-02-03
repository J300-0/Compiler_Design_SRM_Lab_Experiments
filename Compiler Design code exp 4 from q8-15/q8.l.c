%{
#include <stdio.h>
%}

%%
[A-Z]   { printf("%s is an Uppercase letter\n", yytext); }
[a-z]   { printf("%s is a Lowercase letter\n", yytext); }
.|\n    { /* Ignore other characters */ }
%%

int main() {
    printf("Enter text: ");
    yylex();
    return 0;
}
int yywrap() { return 1; }