#include "lattice.h"
#include <stdio.h>

int main(){
  int32_t origin[2] = {0,0};
  int32_t point1[2] = {2,1};
  int32_t point2[2] = {3,0};
  
  lattice *l = create_lattice(origin, point1, point2);
  draw_lattice(l,250,100);
} 
