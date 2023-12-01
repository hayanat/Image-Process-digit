// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H
#define SUCCESS 0

/**
 * @struct matrix_dims
 * @brief Matrix dimensions container. Used in MlpNetwork.h and main.cpp
 */
typedef struct matrix_dims
{
	int rows, cols;
} matrix_dims;


class Matrix {
 private:
  float * _arr;
  int _num_rows;
  int _num_cols;

  int swap_entries(int row1, int col1, int row2, int col2);

 public:
  Matrix (int rows, int cols);  //done
  Matrix () : Matrix (1,1) {} ; // done
  Matrix (const Matrix& matrix); //done
  ~Matrix () { delete _arr;} //done

  int get_rows () const {return _num_rows;}
  int get_cols () const {return _num_cols;}
  float* getData() const { return _arr;}

  Matrix& transpose();
  void  print_matrix() const;


};

#endif //MATRIX_H