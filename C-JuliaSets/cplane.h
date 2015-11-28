// Include the header complex.h
#include "complex.h"

// Define type as abstraction layer to protect against implementation changes
typedef unsigned long int INT;

// Use abstract types inside cplane definition for robustness
typedef struct cplane {
  INT rows;
  INT cols;
  COMPLEX *mat;
} CPLANE;

// Constructor that initializes type in sensible way
CPLANE new_cplane(const INT, const INT);
// Destructor for allocated memory
void delete_cplane(CPLANE);
// Getter for individual elements
COMPLEX get(const CPLANE *, const INT, const INT);
// Setter appropriate cplanes
void set(CPLANE *, const VALUE, const VALUE, const VALUE, const VALUE);
// Constructor that tests some conditions and calls set function
CPLANE constructor(const VALUE, const VALUE, const VALUE, const VALUE, const INT, const INT);
// Abstraction layer for printing matrices
void print_cplane(const CPLANE *);
