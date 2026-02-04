%{
#include <stdio.h>
%}

%%
[aeiouAEIOU]   { printf("%s is a vowel\n", yytext); }
[a-zA-Z]       { printf("%s is not a vowel\n", yytext); }
\n             { return 0; }
%%

int yywrap()
{
    return 1;
}

int main()
{
    printf("Enter a character: ");
    yylex();
    return 0;
}