// Includes the header complex.h
#include "complex.h"

// Defines type as abstraction layer to protect against implementation changes
typedef unsigned long int INT;

// Uses abstract types inside cplane definition for robustness
typedef struct cplane {
  INT rows;
  INT cols;
  COMPLEX *mat;
} CPLANE;

// Declares the functions defined on the .c file
CPLANE new_cplane(const INT, const INT);
void delete_cplane(CPLANE);
COMPLEX get(const CPLANE *, const INT, const INT);
void set(CPLANE *, const VALUE, const VALUE, const VALUE, const VALUE);
CPLANE constructor(const VALUE, const VALUE, const VALUE, const VALUE, const INT, const INT);
void print_cplane(const CPLANE *);
