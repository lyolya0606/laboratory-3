#pragma once

class Array {
private:
  double** arr = nullptr; // ?
  int row = 0;
  int column = 0;

public:
  Array(int rows, int columns);

  ~Array();

  Array(Array&& oldArray);

  Array(const Array& oldArray);

  void Print();

  int GetRow();

  int GetColumn();

  double* operator[](int index);
};