#include <iostream>
#include <string>
#include <sstream>
#include "cplane.h"
#include "julia.h"

#define MAXITER 256

using namespace std;

// Declare a function
int iterate(COMPLEX, COMPLEX &);
 
// Start the main function
int main(void) {
 
  // Define variables to receive the inputs and to work later
  INT i, j, out;
  INT xpoints, ypoints;
  VALUE xmin, xmax, ymin, ymax;
  cplane a;

  // Receive the inputs
  cout << "Enter the minimum value for x-axis: ";
  cin >> xmin;
  cout << endl;
  cout << "Enter the maximum value for x-axis: ";
  cin >> xmax;
  cout << endl;
  cout << "Enter the minimum value for y-axis: ";
  cin >> ymin;
  cout << endl;
  cout << "Enter the maximum value for y-axis: ";
  cin >> ymax;
  cout << endl;
  cout << "Enter the number of points that will be taken in x-axis: ";
  cin >> xpoints;
  cout << endl;
  cout << "Enter the number of points that will be taken in y-axis: ";
  cin >> ypoints;
  cout << endl;

  // Construct the desirable cplane
  a = constructor(xmin, xmax, ymin, ymax, xpoints, ypoints);

  // Receive and print the output of the iterate function for each element of the cplane
  cout << "x, y, out" << endl;
  for(i=0; i<ypoints; i++){
    for(j=0; j<xpoints; j++){
      out = iterate((0, 0), a.mat(i, j));
      cout << real(a.mat(i, j)) << ", " << imag(a.mat(i, j)) << ", " << out << endl;
    }
  }

  // Destruct matrix when done
  a.mat.clear();

  return 0;
}
 
// Iterate the function juliamap
int iterate(COMPLEX z, COMPLEX &c){
  INT i, j, n;
  n=0;
  while(true){
    z = juliamap(z, c);
    n=n+1;
    if(abs(z)>2){
      return n;
    }
    else if(n>=MAXITER){
      return 0;
    }
  }
}
