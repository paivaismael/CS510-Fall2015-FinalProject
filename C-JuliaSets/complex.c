#include<stdio.h>
#include"complex.h"

// Set a complex number
void set_complex(COMPLEX *c, VALUE a, VALUE b){
  c->x=a;
  c->y=b;
}

// Multiply two complex numbers
COMPLEX mult2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)*(b->x)-(a->y)*(b->y);
  z.y=(a->x)*(b->y)+(a->y)*(b->x);
  return z;
}

// Square a complex number
COMPLEX square(COMPLEX *a){
  return mult2(a,a);
}

// Add two complex numbers
COMPLEX add2(COMPLEX *a, COMPLEX *b){
  COMPLEX z;
  z.x=(a->x)+(b->x);
  z.y=(a->y)+(b->y);
  return z;
}

// Apply juliamap to two complex numbers
COMPLEX juliamap(COMPLEX *a, COMPLEX *b){
  COMPLEX c = square(a);
  return add2(&c,b);
}

// Output the square of the module of a complex
VALUE square_mod(COMPLEX *a){
  return (a->x)*(a->x) + (a->y)*(a->y);
}

// Print a complex number
void complex_print(COMPLEX *a){
  if ((a->y)<0){
    printf("%Lf%Lfi",a->x,a->y);
  }
  else{
    printf("%Lf+%Lfi",a->x,a->y);
  }
}
