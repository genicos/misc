#include "stack.h"
#include <stdlib.h>

stack *create_stack(uint32_t length){
  
  stack *s = (stack *)malloc(sizeof(stack));
  if(!s)
    return NULL;
  
  
  s->start = (ELEMENT *)malloc(length*sizeof(ELEMENT));
  if(!s->start)
    return NULL;
  
  s->length = length;
  s->head = 0;

  return s;
}

void delete_stack(stack *s){
  if(s){
   free(s->start);
  }
  free(s);
}

ELEMENT pop(stack *s){
  if(s && s->start && s->head > 0){
    return s->start[--s->head];
  }
  return 0;
}

bool push(stack *s, ELEMENT a){
  if(s && s->start && s->head < s->length){
    s->start[s->head++] = a;
    return true;
  }
  return false;
}
