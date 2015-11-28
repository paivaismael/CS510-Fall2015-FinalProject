#include <iostream>
#include "cplane.h"

std::complex<long double> T;

int main() {
  // Define two 10x10 matrices with element types of long double
  // The first has all elements set to 1.0
  // The second has all elements set to 2.0
  Cplane<long double> cp1(10, 10, 1.0);
  Cplane<long double> cp2(10, 10, 2.0);

/*  // Set a few elements differently as a test of accessors
  cp1(3,4) = complex(10.0,5.0);
  cp2(1,2) = complex(-15.0,6.0);

  // Define a third matrix as the sum of the first two
  Cplane<T> cp3 = cp1 + cp2;

  // Print out the third matrix as a text array
  for (int i=0; i<cp3.get_rows(); i++) {
    for (int j=0; j<cp3.get_cols(); j++) {
      std::cout << cp3(i,j) << ", ";
    }
    std::cout << std::endl;
  }*/

  return 0;
}
