%{
#include <stdio.h>
%}

%%
[a-zA-Z_][a-zA-Z0-9_]* { printf("Valid Identifier\n"); }
[0-9][a-zA-Z0-9_]* { printf("Invalid Identifier (Starts with digit)\n"); }
.+                      { printf("Invalid Identifier\n"); }
\n                      { return 0; }
%%

int main() {
    printf("Enter variable name: ");
    yylex();
    return 0;
}
int yywrap() { return 1; }