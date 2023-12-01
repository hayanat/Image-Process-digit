#include "Matrix.h"
#include <iostream>


// we will do the matrix in one dim

Matrix :: Matrix(int rows, int cols) :_num_rows(rows), _num_cols(cols) {
    _arr = new float [rows * cols]; // create the matrix
    for(int i = 0; i < (rows*cols); i++){  // make it all zero
      _arr[i] = 0;
    }
}

Matrix :: Matrix(const Matrix& matrix){
  _num_cols = matrix._num_cols;
  _num_rows = matrix._num_rows;
  _arr = new float [matrix._num_rows * matrix._num_cols];
  for (int i = 0; i < _num_cols * _num_rows; i++) {
    _arr[i] = matrix._arr[i];
  }
}

int Matrix::swap_entries(int row1, int col1, int row2, int col2){

  int first_index = row1 * _num_cols + col1;
  int second_index = row2 * _num_cols + col2;

  float temp = _arr[first_index];
  _arr[first_index] = _arr[second_index];
  _arr[second_index] = temp;
  return SUCCESS ;
}




Matrix& Matrix:: transpose() {
  for (int i = 0; i < _num_rows * _num_cols; i++) {
    int nextIndex = i;
    while (nextIndex < i || nextIndex == i) {
      nextIndex = (nextIndex % _num_cols) * _num_rows + nextIndex / _num_cols;
    }
    // Swap the current element with the element at its transposed position
    float temp = _arr[i];
    _arr[i] = _arr[nextIndex];
    _arr[nextIndex] = temp;
  }
  return *this;
}



// Print the matrix
void  Matrix::print_matrix() const {
  for (int i = 0; i < _num_rows; i++) {
    for (int j = 0; j < _num_cols; j++) {
      std::cout << _arr[i * _num_cols + j] << " ";
    }
    std::cout << "\n";
  }
}







//Matrix& Matrix::transpose(){
//  int old_cols = _num_cols;
//  int old_rows = _num_rows;
//
//  for(int i =0; i < old_rows * old_cols){
//  int nextIndex = i;
//  while (nextIndex < i || nextIndex == i) {
//    nextIndex = (nextIndex % n) * m + nextIndex / n;
//  }
//  }


//  int half_size = old_cols*old_rows / 2 ;
//  for (int i = 0; i < half_size; i++)
//  {
//    for (int j = 0; j < half_size; j++)
//    {
//      (*this).swap_entries (i, j, j, i);
//    }


    //    int matrix_i_j = _arr[row * _num_cols + col];
    //    int matrix_j_i = _arr[col * _num_cols + row];

//
//  return *this;
//}


