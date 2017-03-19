#ifndef CLASSES81_H
#define CLASSES81_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

static const int ROWS = 80;

using std::cout;
using std::endl;
using std::string;
using std::vector;

class MatrixHolder {

private:
  int matrix[ROWS*ROWS];
  bool visited[ROWS*ROWS];

public:

  int cellValue( int row, int column ) const{
    int location = ROWS*row+column;
    return matrix[location];
  }

  // Check if the cell has been visited and if not, sets it as visited
  bool cellVisited( int row, int column ){
    int location = ROWS*row+column;
    if ( !visited[location] ){
      visited[location] = true;
      return false;
    }
    return true;
  }

  bool readCellVisited( int row, int column ) const{
    int location = ROWS*row+column;
    return visited[location];
  }
  
  MatrixHolder() { 
    std::ifstream readFile("p083_matrix.txt");
    if ( readFile.is_open() ){
      int counter = 0;
      string tmpString;
      while( counter < ROWS*ROWS ){
        ++counter;
        if ( (counter)%ROWS==0 ){
          std::getline( readFile, tmpString );
        } else {
          std::getline( readFile, tmpString, ',' );
        }
        matrix[counter-1] = atoi( tmpString.c_str() );
      }
      if ( counter!= ROWS*ROWS ) { 
        cout << "An error occurred: wrong number of matrix elements" << endl;
      }
    }

    visited[0] = true;
    for (int i = 1; i != ROWS*ROWS; ++i){
      visited[i] = false;
    }
  }

  ~MatrixHolder() { }

  MatrixHolder &operator=(const MatrixHolder &right){
    for (int row = 0; row != ROWS; ++row){
      for (int col = 0; col != ROWS; ++col){
        int location = ROWS*row+col;
        matrix[location] = right.cellValue( row, col );
        visited[location] = right.readCellVisited( row, col );
      }
    }
    return (*this);
  }
};

class Path {

private:
  int row;
  int column;
  int sumValue;
  MatrixHolder *matrix;

public:

  // Default constructor
  Path( MatrixHolder *_matrix ) { 
    matrix = _matrix;
    row = 0;
    column = 0;
    matrix->cellVisited( row, column );
    sumValue = matrix->cellValue( row, column );
  }

  Path( MatrixHolder *_matrix, int _row, int _column, int prevSum ) {
    matrix = _matrix;
    row = _row;
    column = _column;
    sumValue = prevSum;
    sumValue += matrix->cellValue( row, column );
  }

  ~Path() { }

  int getRow() const{ return row; }
  int getCol() const{ return column; }
  int getSum() const{ return sumValue; }

  bool isFinal(){
    if ( (column == (ROWS-1)) && (row == (ROWS-1)) ) return true;
    return false;
  }

  bool operator<(const Path &right) const {
    if ( sumValue == right.getSum() ){
      if ( row == right.getRow() ){
        return column < right.getCol();
      }
      return row < right.getRow();
    }
    return ( sumValue < right.getSum() );
  }

  bool operator==(const Path &right) const {
    return ( sumValue == right.getSum() && row == right.getRow() && column == right.getCol() );
  }

  Path &operator=(const Path &right) {
    row = right.getRow();
    column = right.getCol();
    sumValue = right.getSum();
    return (*this);
  }
};


#endif // CLASSES81_H
