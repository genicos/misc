#include "lattice.h"

//A dither is a container of points
typedef struct dither{
  uint8_t lattice_count;  //
  lattice **lattices;     ///pointer to array of pointers to lattices, length of array is lattice_count
  
  char *expression;       // Null terminated string of '^v()!' and 'A' through 'Z' 
                          // Expression is a logical combination of Lattices, where A is lattices[0] and so on
                          // prefix notation
}

dither *create_dither(uint8_t lattice_count, lattice **lattices, char *expression);

void delete_dither(dither *d);

bool IsInDither(dither *d, uint32_t x, uint32_t y);
