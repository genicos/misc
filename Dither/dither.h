#ifndef __DITHER_H__
#define __DITHER_H__
#include "lattice.h"

//A dither is a container of points
typedef struct dither{
  uint8_t lattice_count;        //
  lattice **lattices;           ///pointer to array of pointers to lattices, length of array is lattice_count
                                
  char *expression;             // non null terminated string of '^v()!' and 'A' through 'Z'                         // expression is a container of chars, those chars have linear order
                                // Expression is a logical combination of Lattices, where A is lattices[0] and so on 
                                // prefix notation
  uint32_t expression_length; //number of characters in expression
} dither;

dither *create_dither(uint8_t lattice_count, uint32_t expression_length);

void delete_dither(dither *d);

bool IsInDither(dither *d, int32_t x, int32_t y);

void draw_dither(dither *d, uint32_t width, uint32_t height);
#endif
