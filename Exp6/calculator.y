%{
#include <stdio.h>
#include <stdlib.h>

/* Function declarations */
void yyerror(const char *s);
int yylex(void);
%}

/* Data type for tokens (we use float for calculation) */
%union {
    float fval;
}

/* Token declarations */
%token <fval> NUMBER
%token EOL

/* Precedence and Associativity */
/* Lowest precedence */
%left '+' '-'
/* Highest precedence */
%left '*' '/'

/* Type definition for non-terminals */
%type <fval> exp

%%

/* Grammar Rules */
input: 
    | input line
    ;

line: EOL
    | exp EOL { printf("Result: %.2f\n> ", $1); }
    ;

exp: NUMBER         { $$ = $1; }
   | exp '+' exp    { $$ = $1 + $3; }
   | exp '-' exp    { $$ = $1 - $3; }
   | exp '*' exp    { $$ = $1 * $3; }
   | exp '/' exp    { 
        if ($3 == 0) {
            yyerror("Cannot divide by zero!");
            $$ = 0;
        } else {
            $$ = $1 / $3; 
        }
    }
   | '(' exp ')'    { $$ = $2; }
   ;

%%

/* C Code Section */
int main() {
    printf("Type an expression (e.g., 2 + 3 * 4) and press Enter.\n> ");
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}