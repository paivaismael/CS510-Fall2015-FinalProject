#include <iostream>
#include "cplane.h"

int main() {
  // Define two 10x10 matrices with element types of long double
  // The first has all elements set to 1.0
  // The second has all elements set to 2.0
  cplane cp1 = constructor(-2, 2, -2, 2, 4, 4);
  print_cplane(cp1);

  return 0;
}
