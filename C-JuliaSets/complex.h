// Define type as abstraction layer to protect against implementation changes
typedef long double VALUE;

// Use abstract types inside complex definition for robustness
typedef struct complex {
  VALUE x;
  VALUE y;
} COMPLEX;

void set_complex(COMPLEX *, VALUE, VALUE);
COMPLEX mult2(COMPLEX *, COMPLEX *);
COMPLEX square(COMPLEX *);
COMPLEX add2(COMPLEX *,COMPLEX *);
COMPLEX juliamap(COMPLEX *, COMPLEX *);
void complex_print(COMPLEX *);
COMPLEX get_result(char *, COMPLEX *, COMPLEX *);
void assert_function(char *, COMPLEX *, COMPLEX *, VALUE, VALUE);
