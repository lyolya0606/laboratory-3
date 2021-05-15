#pragma once
#include "ArrayClass.h"

class Isort {
protected: 
  int permutation = 0;
  int comparison = 0;

public:

  virtual Array Sort(Array arr) = 0;

  int GetPermutation(void);

  int GetComparison(void);

  virtual ~Isort() = default;
};

class BubbleSort : public Isort {
public:
  Array Sort(Array arr);
};

class SelectionSort : public Isort {
public:
  Array Sort(Array arr);
};

class InsertionSort : public Isort {
public:
  Array Sort(Array arr);
};

class ShellSort : public Isort {
public:
  Array Sort(Array arr);
};

class QuickSort : public Isort {
  Array QuickSortRecursion(Array *arr, int start, int end, int i);
  int Separation(Array *arr, int start, int end, int numberOfRow);
public:
  Array Sort(Array arr);
};