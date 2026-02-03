%{
#include <stdio.h>
int flag = 0;
%}

%%
"("     { flag++; }
")"     { flag--; }
\n      { return 0; }
.       ; /* Ignore other characters */
%%

int main() {
    printf("Enter parentheses string (e.g. (()) ): ");
    yylex();
    if(flag == 0) printf("Well Formed Parentheses\n");
    else printf("Not Well Formed\n");
    return 0;
}
int yywrap() { return 1; }