%{
#include <stdio.h>
int pos_count = 0;
int neg_count = 0;
%}

%%
\+?[0-9]+   { pos_count++; printf("Positive: %s\n", yytext); }
-[0-9]+     { neg_count++; printf("Negative: %s\n", yytext); }
.|\n        ; /* Ignore spaces/newlines */
%%

int main() {
    printf("Enter numbers (Press Ctrl+Z then Enter to finish):\n");
    yylex();
    printf("\nTotal Positive: %d", pos_count);
    printf("\nTotal Negative: %d\n", neg_count);
    return 0;
}
int yywrap() { return 1; }