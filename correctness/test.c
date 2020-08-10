#include <stdio.h>
#include "stack.h"


int main(int argc, char **argv){
  argc = 0;
  argv = 0;
  
  stack *s = create_stack(10);
  if(!s){
    printf("Failed to create stack\n");
    return 1;
  }
  printf("Created stack of length 10\n");
  
  for(int h = 0; h<13; h++){
    printf("Pushing %d, push returns %d, head is %d\n", h, push(s,h), s->head);
  }
  for(int h = 0; h<13; h++){
    printf("Popping, pop returned %d, head is %d\n", pop(s), s->head);
  }
  
}



/* 

-O means to ignore the possibility of over flow

-v- -O
  (C <= D)
-^-
*/
int addmore(int32_t C, uint32_t add){
  // -{-
  int D = 0;
  D = C + add;
  // -}-
  return D;
}

