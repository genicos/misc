#ifndef __LATTICE_H__
#define __LATTICE_H__

#include <inttypes.h>
#include <stdbool.h>

// A lattice is a container of 2 dimensional integer points
typedef struct lattice{ 
  int32_t x;             /// (x,y) is in the lattice
  int32_t y;             // 
  int32_t x1;            /// if (a,b) is in the lattice, then (a + x_1, b + y_1) and (a - x_1, b - y_1) are in the lattice
  int32_t y1;            //
  int32_t x2;            /// if (a,b) is in the lattice, then (a + x_2, b + y_2) and (a - x_2, b - y_2) are in the lattice
  int32_t y2;            //
} lattice;

lattice *create_lattice(int32_t origin[2], int32_t point1[2], int32_t point2[2]);

void delete_lattice(lattice *l);

bool IsInLattice(lattice *l, int32_t x, int32_t y);

bool draw_lattice(lattice *l, int32_t width, int32_t height);

#endif
