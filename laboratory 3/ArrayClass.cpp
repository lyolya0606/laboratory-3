#include "ArrayClass.h"
#include <iostream>
#include <iomanip>

using namespace std;

Array::Array(int rows, int columns) : row(rows), column(columns) {
  arr = new double*[row];

  for (int i = 0; i < row; i++) {
    arr[i] = new double[column];
  }
}

Array::~Array() {
  for (int i = 0; i < row; i++) {
    delete arr[i];
  }
  delete[] arr;
  
}

Array::Array(const Array& oldArray) : row(oldArray.row), column(oldArray.column) {
  arr = new double*[row];

  for (int i = 0; i < row; i++) {
    arr[i] = new double[column];
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      arr[i][j] = oldArray.arr[i][j];
    }
  }

};

Array::Array(Array&& oldArray) {
  arr = oldArray.arr;
  row = oldArray.row;
  column = oldArray.column;
  oldArray.arr = nullptr;
  oldArray.row = 0;
  oldArray.column = 0;
}

void Array::Print() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      cout << right << setw(6) << arr[i][j] << "|";
    }
    cout << endl;
  }
}

int Array::GetRow() {
  return row;
}

int Array::GetColumn() {
  return column;
}

double* Array::operator[](int index) {
  return arr[index];
}
