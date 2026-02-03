%{
#include <stdio.h>
%}

%%
a+      { printf("Matched Positive Closure: %s\n", yytext); }
[a-z]+  { printf("Not a positive closure of 'a'\n"); }
.|\n    { return 0; }
%%

int main() {
    printf("Enter string (try 'aaaa'): ");
    yylex();
    return 0;
}
int yywrap() { return 1; }