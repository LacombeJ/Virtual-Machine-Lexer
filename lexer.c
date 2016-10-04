//Compiler Builder 15
//Austin Dragone
//Gabriela Fisher
//Jerasimos Strakosha
//Tarek Medrano
//JonaThan Lacombe



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// List of the tokens we are responsible for handling

typedef enum {  nulsym = 1, identsym, numbersym, plussym, minussym,
  multsym, slashsym, oddsym, eqsym, neqsym, lessym, leqsym,
  gtrsym, geqsym, lparentsym, rparentsym, commasym, semicolonsym,
  periodsym, becomessym, beginsym, endsym, ifsym, thensym,
  whilesym, dosym, callsym, constsym, varsym, procsym, writesym,
  readsym , elsesym} token_type;



union lval {
  char *id;
  char *num; 
} lval; 

token_type lex() {
  char c;
  // ignore space, tab, newline
  while ((c=getchar()) == ' ' || c== '\t' || c == '\n')
    ; 
  if (c == EOF) return nulsym;

  // identifier
  if (isalpha(c)) {
    char sbuf[100], *p = sbuf;
    do {
      *p++ = c;
    } while ((c=getchar()) != EOF && isalnum(c));
    ungetc(c, stdin);
    *p = '\0';
    lval.id = sbuf;
    return identsym;
  }
  
  if (isdigit(c)){
    char sbuf[100], *p = sbuf;
    do {
      *p++ = c;
    } while ((c=getchar()) != EOF && isdigit(c));
    ungetc(c, stdin);
    *p = '\0';
    lval.num = sbuf;
    printf("%s", lval.num);
    return numbersym;  	
  }

  switch (c) {
    case '+' :
      return plussym;
    case '*' :
      return multsym;
    case '(' :
      return lparentsym;
    case ')' :
      return rparentsym;

	
	  
    default  :
      printf("illegal token\n");
  }
}

main() {
  printf("example lexer\n");
  token_type tok;
  while ((tok=lex()) != nulsym) {
    printf("token type: %d", tok);
    if (tok == identsym) printf("%s", lval.id);
    if (tok == numbersym) printf("%s", lval.num);
    printf("\n"); 
  }
}
