#include <stdio.h>
#include <inttypes.h>

int main(){
  int width = 100;
  int height = 100;
  int gap = 12;
  int jump = 2;
  int org = 2;
  for(int j = 0; j < height; j++){
    for(int h = 0; h < width; h++){
      int car = j*jump+ h + org;
      if(car % gap == 0){
        printf("#");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("FUCK a bad ditherere");
}
