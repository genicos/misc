#include <stdio.h>
#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

typedef enum {SEEKING_ASSERTION_OPEN_1, SEEKING_ASSERTION_OPEN_2, SEEKING_ASSERTION_OPEN_3,
              SEEKING_ASSERTION_END_1,  SEEKING_ASSERTION_END_2,  SEEKING_ASSERTION_END_3,
              SEEKING_CODE_OPEN_1,      SEEKING_CODE_OPEN_2,      SEEKING_CODE_OPEN_3,
              SEEKING_CODE_END_1,  SEEKING_CODE_END_2,       SEEKING_CODE_END_3} state;
int main(){
  /*
  char *file_name; //name of file to check for correctness
  file_name = argv[1];
  argc = 0; 
  printf("%s\n",file_name);
  */
  
  uint8_t *assertions = (uint8_t *)malloc(4096);
  if(!assertions){
    printf("Failed to allocate for assertions\n");
    return 1;
  }
  
  uint8_t *code = (uint8_t *)malloc(4096);
  if(!code){
    printf("Failed to allocate for code\n");
    return 1;
  }
  
  bool run = true;
  char c;
  char tokens* = "-v--^--{--}-";
  uint8_t token_index;

  bool reading_assertion = false;
  uint32_t assertion_index = 0;
  bool reading_code = false;
  uint32_t code_index = 0;
  
  while(run){
    c = getchar();
    if(c == tokens[token_index]){
      token_index++;
      if(token_index == 3){
        reading_assertion = true;
      }
    }
    
  }
  printf("nice state %d\n", state);
}
