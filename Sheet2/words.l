%{
#include <stdio.h>

int words = 0;
%}

whitespace		[ \t\n]

%%

^[ \t\n]+	words++;
[ \t\n]+

%%

main(int argc, char **argv) {
  yylex();
  printf("\nNumber of words: %d\n", words);
  return 0;
}

