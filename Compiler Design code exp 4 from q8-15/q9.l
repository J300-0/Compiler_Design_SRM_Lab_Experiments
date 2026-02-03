%{
#include <stdio.h>
%}

%%
[0-9]+      { printf("Input is a Digit\n"); }
[a-zA-Z]+   { printf("Input is a Word\n"); }
.+          { printf("Input is Mixed or Special Character\n"); }
\n          { return 0; }
%%

int main() {
    printf("Enter a string: ");
    yylex();
    return 0;
}
int yywrap() { return 1; }