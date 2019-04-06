/* 
Implementation of the clas My_matrix
*/

#include "My_matrix.h"
#include <stdexcept>

My_matrix::My_matrix()
{
  n=0;
  m=0;
  ptr = nullptr;
}

void My_matrix::allocate_memory()
{
  // add your code here
}

My_matrix::My_matrix(int n1, int m1)
{
  n=n1;
  m = m1;
  ptr = new int*[n];
  for(int i = 0; i < n; i++)
    ptr[i] = new int[m];
}

My_matrix::My_matrix(const My_matrix& mat)
{
  // add your code here
}

// move constructor (optional)
My_matrix::My_matrix(My_matrix&& mat)
{
  // add your code here
}

My_matrix::~My_matrix()
{
  for(int i =0; i<n; i++)
    delete[] ptr[i];
  delete[] ptr;
}

My_matrix& My_matrix::operator=(const My_matrix& mat)
{
  // add your code here
}

// move assignment operator (optional)
My_matrix& My_matrix::operator=(My_matrix&& mat)
{
  // add your code here
}

int My_matrix::number_of_rows() const
{
  return n;
}

int My_matrix::number_of_columns() const
{
  return m;
}

int* My_matrix::operator()(int i) const
{
  // add your code here
  return ptr[i];
}

int My_matrix::operator()(int i, int j) const
{
  return ptr[i][j];
}

int& My_matrix::operator()(int i, int j)
{
  // add your code here
  return ptr[i][j];
}

int My_matrix::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
  // add your code here
  return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
{
  return ptr[i][j];
}

ostream& operator<<(ostream& out, const My_matrix& mat)
{
  for(int i = 0; i < mat.number_of_rows(); i++){
    for(int y = 0; y < mat.number_of_columns(); y++){
      out << mat.elem(i,y);
      out << " ";
    }
    out << "\n";
  }
  
}

istream& operator>>(istream& in, My_matrix& mat)
{
  int m,n;
  cin >> m;
  cin >> n;
  mat.setM(m);
  mat.setN(n);
  for(int i = 0; i < m; i++){
    for(int y = 0; y < n; y++){
      in >> mat.elem(i,y);
    }
  }

}

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
  My_matrix* mat3 = new My_matrix(mat1.number_of_rows(),mat1.number_of_columns());
  for(int i = 0; i < mat3->number_of_rows(); i++){
    for(int y = 0; y < mat3->number_of_columns(); y++){
      mat3->elem(i,y) = mat1.elem(i,y) + mat2.elem(i,y);
    }
  }
  return *mat3;
}

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
{
  // add your code here
}
