// Includes library
#include <stdio.h>
#include <stdlib.h>
#include "cplane.h" // The header cplane already contains the header complex. Then it is not necessary to include it again.

// Initializes matrix in a sensible way
CPLANE new_cplane(const INT xp, const INT yp){
  CPLANE c;
  c.rows = yp;
  c.cols = xp;
  c.mat = (COMPLEX *)calloc(yp * xp, sizeof(COMPLEX));
  if (c.mat == NULL) {
    fprintf(stderr, "ERROR: failed to allocate new_matrix\n");
  }
  return c;
}

// Frees allocated memory after its use to avoid memory leak
void delete_cplane(CPLANE c){
  free(c.mat);
}

// Gets an specific element of c.mat by receiving the pointer to the memory block that contains a cplane
COMPLEX get(const CPLANE *c, const INT row, const INT col){
  if (row < 0 || col < 0 || row >= c->rows || col >= c->cols) {
    fprintf(stderr, "ERROR: indexing cplane outside bounds\n");
    COMPLEX a;
    set_complex(&a,0,0);
    return a;
  }
  return *(c->mat + c->cols * row + col);
}

// Sets appropriate cplanes
void set(CPLANE *c, const VALUE  xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax){
  // Defines the step size for x and y directions
  const VALUE xstep = (xmax - xmin)/(c->cols - 1);
  const VALUE ystep = (ymax - ymin)/(c->rows - 1);
  // Defines counters
  INT i, j;
  // Sets the mat part of the cplane
  for (i=0; i<(c->rows); i++){
    for (j=0; j<(c->cols); j++){
      set_complex(c->mat + (c->cols * i) + j, xmin + j * xstep, ymin + i * ystep);
    }
  }
}

// Verifies if the inputs respect some expected relationships, reporting errors if they do not and calling function set otherwise
CPLANE constructor(const  VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INT xpoints, const INT ypoints){
  // Creates a new CPLANE and allocate appropriated memory to it
  CPLANE c = new_cplane(xpoints,ypoints);  
  // Verifies if the inputs xpoints and ypoints were chosen appropriately
  if (xpoints < 2 || ypoints < 2) {
    fprintf(stderr, "ERROR: xpoints and ypoints should be at least equal to 2\n");
  }
  // Verifies if the inputs xmin and xmax were chosen appropriately
  else if (xmin >= xmax){
    fprintf(stderr, "ERROR: xmax has to be greater than xmin\n");
  }
  // Verifies if the inputs ymin and yman were chosen appropriately
  else if (ymin >= ymax){
    fprintf(stderr, "ERROR: ymax has to be greater than ymin\n");
  }
  else{
    set(&c,xmin, xmax, ymin, ymax);
  }
  return c;
}

// Prints a cplane (It is a helper to test this library)
void print_cplane(const CPLANE *cp){
  INT i, j;
  printf("Cplane (rows: %ld, cols: %ld) \n", cp->rows, cp->cols);
  for(i=0; i<(cp->rows); i++) {
    for(j=0; j<(cp->cols); j++) {
      // Prints values of matrix separated by tabs with each row on a separate line
      COMPLEX z = get(cp, i, j);
      complex_print(&z);
      printf(" ");
    }
    puts("");
  }
  puts("");
}
