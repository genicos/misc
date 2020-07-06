#include "lattice.h"
#include "dither.h"
#include <stdio.h>

int main(){
  int32_t lattice_data[10][6];
  lattice *lattices[10];
  
  
  lattice_data[0][0] = 0;
  lattice_data[0][1] = 0;
  lattice_data[0][2] = 1;
  lattice_data[0][3] = -4;
  lattice_data[0][4] = 7;
  lattice_data[0][5] = 4;
  lattices[0] = create_lattice(&lattice_data[0][0],&lattice_data[0][2],&lattice_data[0][4]);
  draw_lattice(lattices[0],190,100);
  
  lattice_data[1][0] = 0;
  lattice_data[1][1] = 0;
  lattice_data[1][2] = 8;
  lattice_data[1][3] = 2;
  lattice_data[1][4] = -3;
  lattice_data[1][5] = 4;
  lattices[1] = create_lattice(&lattice_data[1][0],&lattice_data[1][2],&lattice_data[1][4]);
  draw_lattice(lattices[1],190,100);
  
  
  char *expression = "(AvB)";
  dither *d = create_dither(2, sizeof(expression) - 1);
  d->lattices = lattices;
  d->expression = expression;

  draw_dither(d,190,100);
} 
