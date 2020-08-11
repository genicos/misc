#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

int main(int argc, char **argv){
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
  uint8_t state = 0;
  while(run){
    c = getchar();
    
  }
}
