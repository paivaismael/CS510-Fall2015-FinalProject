// Include libraries
#include <stdio.h>
#include "cplane.h" // The library cplane already includes the library complex

// Define a global constant
#define MAXITER 256

// Declare a function
int iterate(COMPLEX, COMPLEX *);

// Start the main function
int main(void) {

  // Define variables to receive the inputs and to work later
  INT i, j, out;
  const INT xpoints, ypoints;
  const VALUE xmin, xmax, ymin, ymax, creal, cimag;
  COMPLEX c, z;
  CPLANE a;

  // Receive the inputs
  printf("Enter the minimum value for x-axis: ");
  scanf("%Lf", &xmin);
  printf("\n");
  printf("Enter the maximum value for x-axis: ");
  scanf("%Lf", &xmax);
  printf("\n");
  printf("Enter the minimum value for y-axis: ");
  scanf("%Lf", &ymin);
  printf("\n");
  printf("Enter the maximum value for y-axis: ");
  scanf("%Lf", &ymax);
  printf("\n");
  printf("Enter the number of points that will be taken in x-axis: ");
  scanf("%ld", &xpoints);
  printf("\n");
  printf("Enter the number of points that will be taken in y-axis: ");
  scanf("%ld", &ypoints);
  printf("\n");
  printf("Enter the value for the real part of c: ");
  scanf("%Lf", &creal);
  printf("\n");
  printf("Enter the value for the imaginary part of c: ");
  scanf("%Lf", &cimag);
  printf("\n");

  // Construct the desirable cplane
  a = constructor(xmin, xmax, ymin, ymax, xpoints, ypoints);

  // Construct the complex c
  set_complex(&c, creal, cimag);

  // Receive the output of the iterate function for each element of the cplane
  for(i=0; i<ypoints; i++){
    for(j=0; j<xpoints; j++){
      z = get(&a, i, j);
      out = iterate(z, &c);
      printf("%Lf, %Lf, %ld\n", z.x, z.y, out);
    }
  }

  // Destruct matrix when done
  delete_cplane(a);

  return 0;
}

// Iterate the function juliamap
int iterate(COMPLEX z, COMPLEX *c){
  INT i, j, n;
  n=0;
  for(;;){
    z = juliamap(&z, c);
    n=n+1;
    if(square_mod(&z)>4){
      return n;
    }
    else if(n>=MAXITER){
      return 0;
    }
  }
}
