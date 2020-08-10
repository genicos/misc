#include <inttypes.h>
#include <stdbool.h>

#define ELEMENT uint8_t

typedef struct stack{
  ELEMENT* start;
  uint32_t head;
  uint32_t length;
}stack;

stack* create_stack(uint32_t length);

void delete_stack(stack *s);

//Pops 0 if head=0
ELEMENT pop(stack *s);

bool push(stack *s, ELEMENT a);
