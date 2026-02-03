%{
#include <stdio.h>
int count = 0;
%}

%%
[a-zA-Z0-9]+    { count++; }
[+\-*/=]        { count++; } /* Operators as tokens */
[ \t\n]         { /* Ignore spaces */ }
.               { /* Ignore others */ }
%%

int main() {
    printf("Enter code/text (Press Ctrl+Z then Enter to finish on Windows):\n");
    yylex();
    printf("\nTotal number of tokens: %d\n", count);
    return 0;
}
int yywrap() { return 1; }