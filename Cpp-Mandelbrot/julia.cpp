// Pre-processor directives to prevent redundant library loading
#ifndef __JULIA_CPP
#define __JULIA_CPP

// Include header declarations of useful libraries
#include "julia.h"

// Applies juliamap to two complex numbers
COMPLEX juliamap(COMPLEX &z, COMPLEX &c){
  return (z * z) + c;
}

#endif
