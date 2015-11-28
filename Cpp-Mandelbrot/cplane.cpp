// Pre-processor directives to prevent redundant library loading
#ifndef __CPLANE_CPP
#define __CPLANE_CPP

// include the header declarations
#include "cplane.h"

using namespace std;
using namespace boost::numeric::ublas;

void set(cplane &cp, const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax){
  const VALUE xstep = (xmax - xmin)/(cp.cols - 1);
  const VALUE ystep = (ymax - ymin)/(cp.rows - 1);
  INT i, j;
  COMPLEX z;
  for (i=0; i<cp.rows; i++){
    for (j=0; j<cp.cols; j++){
        cp.mat.resize(i,j);
        real(z)=xmin + j * xstep;
        imag(z)=ymin + i * ystep;
        cp.mat(i,j) = z;
    }
  }
}

cplane constructor(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INT xpoints, const INT ypoints){
  cplane c;
  c.rows = ypoints;
  c.cols = xpoints;
  c.mat (c.rows, c.cols);
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
    c.rows = ypoints;
    c.cols = xpoints;
    c.mat (c.rows,c.cols);
    set(c, xmin, xmax, ymin, ymax);
  }
  return c;
}

void print_cplane(cplane &cp){
  INT i, j;
  cout << "Cplane (rows: " << cp.rows << ", cols: " << cp.cols << ")" << endl;
  for(i=0; i<cp.rows; i++) {
    for(j=0; j<cp.cols; j++) {
      cp.mat.resize(i+1,j+1);
      cout << cp.mat(i,j) << " ";
    }
    cout << endl;
  }
  cout << endl;
}

#endif
