#include "lattice.h"
#include "dither.h"
#include <stdio.h>

int main(){
  int32_t origin[2] = {0,0};
  int32_t point1[2] = {2,-8};
  int32_t point2[2] = {4, -1};
  
  lattice *l = create_lattice(origin, point1, point2);
  draw_lattice(l,190,100);
  
  printf("\n\n\n\n\n****************\n\n\n");

  int32_t norgin[2] = {0,0};
  int32_t noint1[2] = {4,1};
  int32_t noint2[2] = {-2,3};

  lattice *la = create_lattice(norgin, noint1, noint2);
  draw_lattice(la,190,100);
  
  printf("\n\n\n\n\n****************\n\n\n");

  char *expression = "(A^!B)";
  dither *d = create_dither(2, sizeof(expression) - 1);
  d->lattices[0] = l;
  d->lattices[1] = la;
  d->expression = expression;

  draw_dither(d,190,100);
} 
