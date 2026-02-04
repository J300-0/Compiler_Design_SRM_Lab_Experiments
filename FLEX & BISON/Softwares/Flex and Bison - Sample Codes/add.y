%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);
%}

%token NUMBER

%%
stmt:
    NUMBER '+' NUMBER '\n'
    {
        printf("Sum = %d\n", $1 + $3);
    }
    ;
%%
void yyerror(const char *s)
{
    printf("Error\n");
}

int main()
{
    printf("Enter two numbers with + operator: ");
    yyparse();
    return 0;
}