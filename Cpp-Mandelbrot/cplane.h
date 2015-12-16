// Pre-processor directives to prevent redundant library loading
#ifndef __MPLANE_H
#define __CPLANE_H

// Includes libraries
#include <boost/numeric/ublas/matrix.hpp>
#include <complex>

// Defines types
typedef long int INT;
typedef long double VALUE;
typedef std::complex<long double> COMPLEX;

// Defines a class called cplane
class cplane {
  public:
    INT rows;
    INT cols;
    boost::numeric::ublas::matrix<std::complex<long double> > mat;
};

// Declares functions defined in the .cpp file
void set(cplane &, const VALUE, const VALUE, const VALUE, const VALUE);
cplane constructor(const VALUE, const VALUE, const VALUE, const VALUE, const INT, const INT);
void print_cplane(cplane &);

#endif