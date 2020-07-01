#include <stdio.h>
#include <inttypes.h>
#include <bool.h>

//A lattice is a container of points
//  
typedef struct lattice{
  int32_t x0;         // (x0,y0) is in the lattice
  int32_t y0;

  int32_t x1;         // if a point (a,b) is in the lattice, (a + x1, b + y1) and (a - x1, b - y2) are in the lattice
  int32_t y1;

  int32_t x2;         // if a point (a,b) is in the lattice, (a + x2, b + y2) and (a - x2, b - y2) are in the lattice
  int32_t y2;
} lattice;

Lattice *create_lattice(){
  Lattice *l = (Lattice *)malloc(sizeof(Lattice));
  
}

bool IsIn(Lattice *l, int32_t x, int32_t y){
  x -= l->x0;
  y -= l->y0;

  int32_t det = l->x1 * l->y2 - l->x2 * l->y1;
  
  if(det){
    return (x * l->y2 - y * l->x2) % det == 0 && (l->x1 * y - l->y1 * x) % det == 0;
  }else{
    int32_t common_denominator_x = x1;
    int32_t common_denominator_y = y1;
    if(math.abs(l->x1) > math.abs(l->x2)){
      common_denominator_x = x2;
      common_denominator_y = y2;
    }
    return (x % common_denominator_x) == 0 && (y % common_denominator_y) == 0;
  }
}
