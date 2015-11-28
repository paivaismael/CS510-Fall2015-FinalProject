// Pre-processor directives to prevent redundant library loading
#ifndef __MATRIX_CPP
#define __MATRIX_CPP

// include the header declarations
#include "cplane.h"

//*************
//
// CONSTRUCTORS
//
//*************

// Default constructor
template<typename T>
Cplane<T>::Cplane(unsigned int _rows, unsigned int _cols, const T& _initial) {
  // use vector method to resize outer vector of rows to length _rows
  mat.resize(_rows);
  for (unsigned int i=0; i<mat.size(); i++) {
    // for each row, resize to length _cols of columns
    // and initialize elements to value _initial
    mat[i].resize(_cols, _initial);
  }
  // set private fields rows and cols properly
  rows = _rows;
  cols = _cols;
}

// Copy-constructor
template<typename T>
Cplane<T>::Cplane(const Cplane<T>& rhs) {
  // Simply set private fields according to fields
  // of existing Matrix<T> object
  mat = rhs.mat;
  rows = rhs.get_rows();
  cols = rhs.get_cols();
}

// Destructor
// No memory is dynamically allocated in the class,
// so just use default compiler cleanup of memory 
template<typename T>
Cplane<T>::~Cplane() {}



//*************
//
// ACCESSORS
//
//*************


// Access individual elements
template<typename T>
T& Cplane<T>::operator() (const unsigned int &row, const unsigned int &col) {
  return this->mat[row][col];
}

// Access individual elements (const)
template<typename T>
const T& Cplane<T>::operator() (const unsigned int &row, const unsigned int &col) 
const {
  return this->mat[row][col];
}

// Get number of rows
template<typename T>
unsigned int Cplane<T>::get_rows() const {
  return this->rows;
}

// Get number of cols
template<typename T>
unsigned int Cplane<T>::get_cols() const {
  return this->cols;
}


//*********************
//
// OPERATOR OVERLOADING
//
//*********************

// Assignment operator
template<typename T>
Cplane<T>& Cplane<T>::operator=(const Cplane<T>& rhs) {
  // If assigning to itself, just return itself
  if (&rhs == this)
    return *this;

  // Store new rows and cols
  unsigned int new_rows = rhs.get_rows();
  unsigned int new_cols = rhs.get_cols();

  // resize to new number of rows
  mat.resize(new_rows);
  // resize each row to new number of cols
  for (unsigned int i=0; i<mat.size(); i++) {
    mat[i].resize(new_cols);
  }

  // assign each element 
  for (unsigned int i=0; i<new_rows; i++) {
    for (unsigned int j=0; j<new_cols; j++) {
      mat[i][j] = rhs(i, j);
    }
  }

  // store new number of rows and columns
  rows = new_rows;
  cols = new_cols;

  // return newly modified object
  return *this;
}


// Addition of two matrices
template<typename T>
Cplane<T> Cplane<T>::operator+(const Cplane<T>& rhs) {
  // Create new matrix to store result, initialize to zero
  Cplane result(rows, cols, 0.0);

  // Add each matrix element-by-element
  for (unsigned int i=0; i<rows; i++) {
    for (unsigned int j=0; j<cols; j++) {
      result(i,j) = this->mat[i][j] + rhs(i,j);
    }
  }

  return result;
}

#endif
