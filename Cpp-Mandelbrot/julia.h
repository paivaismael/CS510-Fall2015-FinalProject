// Pre-processor directives to prevent redundant library loading
#ifndef __JULIA_H
#define __JULIA_H

// Includes library 
#include <complex>

// Defines a type
typedef std::complex<long double> COMPLEX;

// Declares funtions defined in .cpp file
COMPLEX juliamap(COMPLEX &, COMPLEX &);
 
#endif
