#include "dither.h"
#include <stdlib.h>
#include <stdio.h>

// binary means only 2 arguments per connective and every connective must have 2 arguments
// infix means that connectives appear between their arguments
// strict means that every connectives must have a corrosponding pair of parenthesis

#define BINARY_INFIX_STRICT 0  
#define BINARY_PREFIX 1


//does not save space for expression
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

  return d;
}

void delete_dither(dither *d){
  if(d){
    free(d->lattices);
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
  if(length==0){                  //First base case, empty string
    return true;
  }
  if(length==1){
    if(expression[0] == '1'){     //Second base case, a singular term
      return true;
    }
    if((expression[0] - 'A') >= 0 && (expression[0] - 'A') < d->lattice_count){
      return IsInLattice(d->lattices[expression[0] - 'A'], x, y);
    }
    return false;
  }
  if(expression[0] == '!'){
    return !solve_binary_infix_strict_expression(d, x, y, expression + 1, length - 1);
  }
  else if(expression[0] == '('){
    int level = 0;   //When we encounter an '(', we increase the level,
                     //When we encounter an ')', we decrease the level
    
    char *first_operand, *second_operand;
    uint32_t first_operand_length, second_operand_length;
    
    bool operator_is_found = false;
    bool operator_is_and = false;

    uint32_t i = 1;       //The character after the initial '(' 
    first_operand = &expression[1];
    
    for(;i < length; i++){
      switch(expression[i]){
        case '(':
          level++;
	break;
        case ')':
          level--;
	break;
	case '^':
	  if(level == 0 && !operator_is_found){
            first_operand_length = i - 1;
	    operator_is_found = true;
	    operator_is_and = true;
	  }
	break;
	case 'v':
	  if(level == 0 && !operator_is_found){
	    first_operand_length = i - 1;
            operator_is_found = true;
	  }
	break;
      }
      
      if(level < 0){
	if (operator_is_found){
	  second_operand = &expression[1 + first_operand_length + 1];
	  second_operand_length = i - (1 + first_operand_length + 1);

	  
	  bool first_operand_value = solve_binary_infix_strict_expression(d, x, y, first_operand, first_operand_length);
	  bool second_operand_value = solve_binary_infix_strict_expression(d, x, y, second_operand, second_operand_length);
	  if(operator_is_and){
            return first_operand_value && second_operand_value;
          }else{
            return first_operand_value || second_operand_value;
          }
	}
        else{
          return false; //Invalid expression, missing operand or missplaced parenthesis
	}
      }
    } 
  }

  return false;
}

bool IsInDither(dither *d, int32_t x, int32_t y){
  return solve_binary_infix_strict_expression(d, x, y, d->expression, d->expression_length);
}

void draw_dither(dither *d, uint32_t width, uint32_t height){
  if(!d){
    return;
  }
  for(uint32_t y = 0; y < height; y++){
    for(uint32_t x =  0; x < width; x++){
      if(IsInDither(d,x,y)){
        putchar('#');
      }else{
        putchar(' ');
      }
    }
    putchar('\n');
  }
}


