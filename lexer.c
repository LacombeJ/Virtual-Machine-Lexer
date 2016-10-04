// Compiler Builder 15
// Austin Dragone
// Gabriela Fisher
// Jerasimos Strakosha
// Tarek Medrano
// JonaThan Lacombe


// 99% of this is taken from the example lexer, and we just need to add in the rest of the tokens
// and format it so that the output matches what is expected.

// nulsym, identsym, numbersym, plussym, multsym, lparentsym,
// rparentsym are completed already.
// our job is to split the other 26.


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

char *keyword[] = {"null", "begin", "call", "const", "do", "else", "end", "if", "odd", "procedure", "read",
	"then", "var", "while", "write"};

union lval {
	char *id;
	int num; 
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
    
		printf("\n"); 
  }
}
