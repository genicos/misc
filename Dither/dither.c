#include "dither.h"

// binary means only 2 arguments per connective and every connective must have 2 arguments
// infix means that connectives appear between their arguments
// strict means that every connectives must have a corrosponding pair of parenthesis

#define BINARY_INFIX_STRICT 0  
#define BINARY_PREFIX 1

dither *create_dither(uint8_t lattice_count, uint32_t expression_length){
  dither *d = (dither *)malloc(sizeof(dither));
  if(!d){
    return NULL;
  }
  

  d->lattice_count = lattice_count;

  d->lattices = (lattice **)malloc(sizeof(lattice *) * lattice_count);
  if(!d->lattices){
    return NULL;
  }
  
  d->expression_length = expression_length;

  d->expression = (char *)malloc(expression_length);
  if(!d->expression){
    return NULL;
  }

  return d;
}

void delete_dither(dither *d){
  if(d){
    free(d->lattice);
    free(d->expression);
    free(d);
  }
}

// Solves a boolean expression,
// characters 'A'-'Z' serve as terms(with char a having the value IsInLattice(d->lattices[a-'A']) )
// '1' serves as True, '0' serves as False
// an empty expression is True
// an invalid expression is False
//   Some examples of binary infix strict expressions, where % is a term or a binary infix strict expression:
// "%"
// "!%"
// "(%^%)"
// "(%v%)"

bool solve_binary_infix_strict_expression(dither *d, int32_t x, int32_t y, char *expression, uint32_t length){
  if(length==0){
    return true;
  }
  if(length==1){
    if(expression[0] == '1'){
      return true;
    }
    if((expression[0] - 'A') >= 0 && (expression[0] - 'A') < d->lattice_count){
      return IsInLattice(d->lattices[expression[0] - 'A'], x, y);
    }
    return false;
  }
  if(expression[0] == '!'){
    return solve_binary_infix_strict_expression(d, x, y, expression + 1, length - 1);
  }
  else if(expression[0] == '('){
    int level = 0;
    for(int h = 1; h< d->expression_length; h++){
      if(level == 0) and //FUCK LIFE
    }
  }
}

bool IsInDither(dither *d, int32_t x, int32_t y){
  return solve_expression(d, x, y, d->expression, d->expression_length);
}


