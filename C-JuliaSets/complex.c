#include<stdio.h>
#include"complex.h"

// Sets a complex number
void set_complex(COMPLEX *c, VALUE a, VALUE b){
  c->x=a;
  c->y=b;
}

// Multiplies two complex numbers
COMPLEX mult2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)*(b->x)-(a->y)*(b->y);
  z.y=(a->x)*(b->y)+(a->y)*(b->x);
  return z;
}

// Squares a complex number
COMPLEX square(COMPLEX *a){
  return mult2(a,a);
}

// Adds two complex numbers
COMPLEX add2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)+(b->x);
  z.y=(a->y)+(b->y);
  return z;
}

// Applies juliamap to two complex numbers
COMPLEX juliamap(COMPLEX *a, COMPLEX *b){
  COMPLEX c = square(a);
  return add2(&c,b);
}

// Outputs the square of the module of a complex
VALUE square_mod(COMPLEX *a){
  return (a->x)*(a->x) + (a->y)*(a->y);
}

// Prints a complex number (It is a helper to test this library)
void complex_print(COMPLEX *a){
  if ((a->y)<0){
    printf("%Lf%Lfi",a->x,a->y);
  }
  else{
    printf("%Lf+%Lfi",a->x,a->y);
  }
}
