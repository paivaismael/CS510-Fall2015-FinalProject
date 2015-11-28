#ifndef __MATRIX_H
#define __MATRIX_H

// Most useful standard library implementation of a vector
#include <vector>

#include <complex>


// A template allows a type T to be passed into a class as a
// parameter, so a single class definition can use different types 
template <typename T> class Cplane {

  private:
    // Implementation section
    //
    // Defining the type to store the plan in mat, with each element of type T
    std::vector<std::vector<T> > mat;
    // Also store the number of rows and columns 
    unsigned int rows;
    unsigned int cols;

  public:
    // Interface section
    //
    // Default constructor, make matrix entries all one value of type T
    Cplane(unsigned int _rows, unsigned int _cols, const T& _initial);
    // Alternate copy-constructor
    Cplane(const Cplane<T> &rhs);
    // Destructor - deallocates memory
    virtual ~Cplane();

    // Defines the assignment = operator 
    Cplane<T>& operator=(const Cplane<T>& rhs);

    // Defines the + operator between matrices
    Cplane<T> operator+(const Cplane<T>& rhs);

    // Defines the selection operator (i,j) to access elements
    T& operator()(const unsigned int &row, const unsigned int &col);
    const T& operator()(const unsigned int &row, const unsigned int &col) const;

    // Accessors for row and column sizes
    unsigned int get_rows() const;
    unsigned int get_cols() const;

};


// C++ requires seeing both the source code and declarations simultaneously
// when dealing with templates (arbitrary types T)
#include "cplane.cpp"

#endif
