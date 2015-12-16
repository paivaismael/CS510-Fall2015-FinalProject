// Includes libraries
#include <stdio.h>
#include "cplane.h" // The library cplane already includes the library complex

// Defines a global constant
#define MAXITER 256

// Declares a function
int iterate(COMPLEX, COMPLEX *);

// Starts the main function
int main(void) {

  // Defines variables to receive inputs and to work with later
  INT i, j, out;
  INT xpoints, ypoints;
  VALUE xmin, xmax, ymin, ymax, creal, cimag;
  COMPLEX c, z;
  CPLANE a;

  // Receives inputs
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

  // Constructs the desirable cplane
  a = constructor(xmin, xmax, ymin, ymax, xpoints, ypoints);

  // Constructs the complex c
  set_complex(&c, creal, cimag);

  // Receives and prints the output of the iterate function for each element of the cplane
  printf("x, y, out\n");
  for(i=0; i<ypoints; i++){
    for(j=0; j<xpoints; j++){
      z = get(&a, i, j);
      out = iterate(z, &c);
      printf("%Lf, %Lf, %ld\n", z.x, z.y, out);
    }
  }

  // Destructs matrix when done
  delete_cplane(a);

  return 0;
}

// Iterates the function juliamap
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
