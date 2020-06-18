#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct dither{
  int gap;
  int jump;
  int org;
} dither;

typedef struct field{
  dither **table; //sum of products, 2D table of pointers, points to first corner
  int clauses;
  int csize;
} field;

void drawd(dither *d, int width, int height){ 
  for(int j = 0; j < height; j++){
    for(int h = 0; h < width; h++){
      int car = j*d->jump+ h + d->org;
      if(car % d->gap == 0){
        printf("#");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

void drawfield(field *f, int width, int height){
  for(int j = 0; j < height; j++){
    for(int h = 0; h < width; h++){
      bool square = false;
      for(int o = 0; o < f->clauses; o++){
        bool intersection = true;
        for(int a = 0; a < f->csize; a++){
          if(f->table[o*f->csize + a]){
            dither *d = f->table[o*f->csize + a];
            intersection = intersection && (j*d->jump + h + d->org % d->gap == 0);
          }
          printf("%d",intersection);
        }
        square = square || intersection;
        printf("b%d",square);
      }
      if(square){
        printf("#");
      }else{
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(){
  int width = 100;
  int height = 30;
  
  dither *first = malloc(sizeof(dither));
  
  first->gap = 12;
  first->jump = 2;
  first->org = 2;
  
  dither *sec = malloc(sizeof(dither));
  sec->gap = 7;
  sec->jump = 2;
  sec->org = 1;

  drawd(first,width,height);
  
  drawd(sec,width,height);
  
  
  field *f = malloc(sizeof(field));
  f->clauses = 2;
  f->csize = 1;
  f->table = malloc(sizeof(dither*)*2);
  f->table[0] = first;
  f->table[1] = sec;
  
  drawfield(f,width,height);
}
