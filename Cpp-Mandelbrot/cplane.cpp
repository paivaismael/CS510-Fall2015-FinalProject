// Pre-processor directives to prevent redundant library loading
#ifndef __CPLANE_CPP
#define __CPLANE_CPP

// Includes the header declarations of important libraries
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include "cplane.h"

// Uses namespace to simplify the writing of the code
using namespace std;
using namespace boost::numeric::ublas;

// Sets an appropriated cplane
void set(cplane &cp, const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax){
  const VALUE xstep = (xmax - xmin)/(cp.cols - 1);
  const VALUE ystep = (ymax - ymin)/(cp.rows - 1);
  INT i, j;
  COMPLEX z;
  for (i=0; i<cp.rows; i++){
    for (j=0; j<cp.cols; j++){
        real(z) = xmin + j * xstep;
        imag(z) = imag(z)=ymin + i * ystep;
        cp.mat(i,j) = z;
    }
  }
}

// Verifies if the values received are adequated and, if that is the case, allocates space and calls the function set
cplane constructor(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INT xpoints, const INT ypoints){
  cplane c;
  c.rows = ypoints;
  c.cols = xpoints;
  if (xpoints < 2 || ypoints < 2) {
    cout << "ERROR: xpoints and ypoints should be at least equal to 2" << endl;
  }
  else if (xmin >= xmax){
    cout << "ERROR: xmax has to be greater than xmin" << endl;
  }
  else if (ymin >= ymax){
    cout << "ERROR: ymax has to be greater than ymin" << endl;
  }
  else{
    c.mat.resize(c.rows, c.cols);
    set(c, xmin, xmax, ymin, ymax);
  }
  return c;
}

// Prints a cplane (It is a helper to test this library)
void print_cplane(cplane &cp){
  INT i, j;
  cout << "Cplane (rows: " << cp.rows << ", cols: " << cp.cols << ")" << endl;
  for(i=0; i<cp.rows; i++) {
    for(j=0; j<cp.cols; j++) {
     cout << cp.mat(i,j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

#endif
