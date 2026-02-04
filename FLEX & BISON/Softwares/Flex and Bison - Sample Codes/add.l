%{
#include "add.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+   { yylval = atoi(yytext); return NUMBER; }
[ \t]    ;        /* ignore spaces */
\n       { return '\n'; }
\+       { return '+'; }
%%
int yywrap()
{
    return 1;
}