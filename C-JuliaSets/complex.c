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

// Print a complex number
void complex_print(COMPLEX *a){
  printf("%Lf+%Lfi",a->x,a->y);
}

// This is a helper for the next function
// It returns the result of the desirable function among
// the functions defined above (mult2, square, add2, juliamap)
COMPLEX get_result(char *name, COMPLEX *a, COMPLEX *b){
  COMPLEX c;
  if(strcmp("mult2",name)==0){
    c=mult2(a,b);
  }
  else if(strcmp("square",name)==0){
    c=square(a);
  }
  else if(strcmp("add2",name)==0){
    c=add2(a,b);
  }
  else if(strcmp("juliamap",name)==0){
    c=juliamap(a,b);
  }
  return c;
}

// This is a helper for test files
// It verifies if the fuctions defined above work correctly and
// return a message informing if it is working correctly or not
void assert_function(char *function, COMPLEX *a, COMPLEX *b, VALUE cx, VALUE cy){
  COMPLEX c;
  c=get_result(function, a, b);
  if(c.x!=cx){
    printf("ERROR: The function %s is not outputing correct results.\n", function);
  }
  else if (c.y!=cy){
    printf("ERROR: The function %s is not outputing correct results.\n", function);
  }
  else{
    printf("The function %s is working correctly.\n", function);
  }
}
