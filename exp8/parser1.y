%{
  /* Definition section */
  #include <stdio.h>
  #include <stdlib.h>
  extern int yylex();
  void yyerror(const char *str) {
    printf("\nSequence Rejected\n");
  }
%}
%token ZERO ONE

/* Rule Section */
%%
r : s {printf("\nSequence Accepted\n\n");};
s : n | ZERO a | ONE a;
a : n a | ZERO | ONE;
n : ZERO | ONE;
%%

#include "lex.yy.c"
//driver code
int main(){
  printf("\nEnter Sequence : ");
  yyparse();
  printf("\n");
  return 0;
}