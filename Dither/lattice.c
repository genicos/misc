#include "lattice.h"
#include <stdlib.h>
#include <stdio.h>

lattice *create_lattice(int32_t origin[2], int32_t point1[2], int32_t point2[2]){
  lattice *l = (lattice *)malloc(sizeof(lattice));
  if(!l){
    return NULL;
  }
  l->x = origin[0];
  l->y = origin[1];
  l->x1 = point1[0];
  l->y1 = point1[1];
  l->x2 = point2[0];
  l->y2 = point2[1];

  return l;
}

void delete_lattice(lattice *l){
  free(l);
}


bool IsInLattice(lattice *l, int32_t x, int32_t y){
  if(!l){
    return false;
  }
  
  x -= l->x; //translate to a new frame where the origin is in the lattice
  y -= l->y; //

  // consider the following matrix equation [x1, x2] [a] = [x] , if an integer solution for a and b exists, then (x, y)
  //                                        [y1, y2] [b]   [y]



  int32_t det = l->x1 * l->y2 - l->x2 * l->y1; //storing determinant of the matrix [x1, x2] for the use of cramers rule
                                               //                                  [y1, y2]
    
  if(det){
    return (x * l->y2 - y * l->x2) % det == 0 && (l->x1 * y - l->y1 * x) % det == 0;
  }else{
    int32_t common_denominator_x = l->x1;
    int32_t common_denominator_y = l->y1;
    if(abs(l->x1) > abs(l->x2)){
      common_denominator_x = l->x2;
      common_denominator_y = l->y2;
    }
    if(common_denominator_x && common_denominator_y){
      return (x % common_denominator_x) == 0 && (y % common_denominator_y) == 0;
    }else{
      return false;
    }
  }
}



bool draw_lattice(lattice *l, int32_t width, int32_t height){
  if(!l){
    return false;
  }
  for(int y = 0; y < height; y++){
    for(int x = 0; x < width; x++){
      
      if(IsInLattice(l, x,y))
        putchar('#');
      else
        putchar(' ');
    }
    putchar('\n');
  }
  return true;
}
