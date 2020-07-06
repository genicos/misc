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

bool solve_binary_infix_strict_expression(dither *d, int32_t x, int32_t y, char *expression, uint32_t length){
  
  for(int h = 0; h < length; h++){
    if(expression[h] == '('){
      
    }
  }
}

bool IsInDither(dither *d, int32_t x, int32_t y){
  return solve_expression(d, x, y, d->expression, d->expression_length);
}


