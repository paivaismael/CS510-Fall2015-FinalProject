// Defines type as abstraction layer to protect against implementation changes
typedef long double VALUE;

// Uses abstract types inside complex definition for robustness
typedef struct complex {
  VALUE x;
  VALUE y;
} COMPLEX;

// Declares the functions constructed on .c file
void set_complex(COMPLEX *, VALUE, VALUE);
COMPLEX mult2(COMPLEX *, COMPLEX *);
COMPLEX square(COMPLEX *);
COMPLEX add2(COMPLEX *,COMPLEX *);
COMPLEX juliamap(COMPLEX *, COMPLEX *);
VALUE square_mod(COMPLEX *);
void complex_print(COMPLEX *);
