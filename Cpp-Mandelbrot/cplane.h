#ifndef __MPLANE_H
#define __CPLANE_H

// Most useful standard library implementation of a vector
#include <boost/numeric/ublas/matrix.hpp>
#include <complex>

typedef long int INT;
typedef long double VALUE;
typedef std::complex<long double> COMPLEX;

class cplane {
  public:
    INT rows;
    INT cols;
    boost::numeric::ublas::matrix<std::complex<long double> > mat;
};

void set(cplane &, const VALUE, const VALUE, const VALUE, const VALUE);
cplane constructor(const VALUE, const VALUE, const VALUE, const VALUE, const INT, const INT);
void print_cplane(cplane &);

#endif
