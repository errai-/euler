#include <iostream>
#include <fstream>
#include "81Clases.h"
#include <set>

using std::cout;
using std::endl;
using std::set;

int takeStep( MatrixHolder &matrix, set<Path> &threads ){

  Path next( &matrix );
  auto iter = threads.begin();
  next = *iter;
  threads.erase(iter);

  //cout << "Row: " << next.getRow() << " Col: " << next.getCol() << " Sum: " << next.getSum() << endl;
  if (next.isFinal()){
    return next.getSum();
  }


  int newRowR = next.getRow()+1, newRowC = next.getCol();
  if ( (newRowR<ROWS) && !( matrix.cellVisited( newRowR, newRowC ) ) ){
    Path newRow( &matrix, newRowR, newRowC, next.getSum() );
    threads.insert( newRow );
  }

  int newColR = next.getRow(), newColC = next.getCol()+1;
  if ( (newColC<ROWS) && !( matrix.cellVisited( newColR, newColC ) ) ){
    Path newCol( &matrix, newColR, newColC, next.getSum() );
    threads.insert( newCol );
  }

  return 0;
}



int main(void){

  MatrixHolder matrix;

  std::set<Path> threads;
  threads.insert( Path( &matrix ) );

  int result = 0;

  while( !result ){
    result = takeStep( matrix, threads );
  }
  cout << "The shortest path is: " << result << endl;
  return 0;
}
