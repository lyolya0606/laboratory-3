#include <iostream>
#include "Isort.h"
#include "ArrayClass.h"

using namespace std;

int Isort::GetPermutation(void) {
  return permutation;
}

int Isort::GetComparison(void) {
  return comparison;
}

Array BubbleSort::Sort(Array arr) {
  for (int i = 0; i < arr.GetRow(); i++) { 

    for (int k = 0; k < arr.GetColumn(); k++) {

      int checking = 0;
      for (int j = 0; j < arr.GetColumn() - 1; j++) {
        comparison++;

        if (fabs(arr[i][j]) > fabs(arr[i][j + 1])) { 
          swap(arr[i][j], arr[i][j + 1]);
          permutation++;
          checking++;
        }
      }
      if (checking == 0) {
        break;
      }
    }
  }
  return arr;
}


Array SelectionSort::Sort(Array arr) {
  for (int i = 0; i < arr.GetRow(); i++) {

    for (int j = 0; j < arr.GetColumn() - 1; j++) {
      int min = j;

        for (int k = j + 1; k < arr.GetColumn(); k++) {
    
          comparison++;
          if (fabs(arr[i][min]) > fabs(arr[i][k])) {
      			min = k;
    			}
      	}
      if (min != j) {
        swap(arr[i][min], arr[i][j]);
        permutation++;
      }
  	}
  }
  return arr;
}



Array InsertionSort::Sort(Array arr) {
  int k = 0;
  double tmp = 0;

  for (int i = 0; i < arr.GetRow(); i++) {
    
    for (int j = 1; j < arr.GetColumn(); j++) {
      tmp = arr[i][j];
      k = j;

      comparison++;
      while ((k > 0) && (fabs(arr[i][k - 1]) > fabs(tmp))) {
        arr[i][k] = arr[i][k - 1];
        comparison++;
        permutation++;
        k--;
      }
      arr[i][k] = tmp;
      
    }
  }
  return arr;
}


Array ShellSort::Sort(Array arr) {
  for (int i = 0; i < arr.GetRow(); i++) {

    for (int h = arr.GetColumn() / 2; h > 0; h /= 2) {

      for (int j = h; j < arr.GetColumn(); j++) {
        int k = j;

        comparison++;
        while (fabs(arr[i][k]) < fabs(arr[i][k - h]) && (k - h) >= 0) {

          swap(arr[i][k], arr[i][k - h]);
          k -= h;
          permutation++;
          comparison++;

        }
      }
    }
  }
  return arr;  
}


int QuickSort::Separation(Array *arr, int start, int end, int numberOfRow) {
  int h = start;

  for (int k = h + 1; k < end; k++) {

    comparison++;
    if (fabs((*arr)[numberOfRow][h]) > fabs((*arr)[numberOfRow][k])) {
      double tmp = (*arr)[numberOfRow][k];

      for (int j = k; j > h; j--) {
        (*arr)[numberOfRow][j] = (*arr)[numberOfRow][j - 1];
        permutation++;
      }
      (*arr)[numberOfRow][h] = tmp;
      h++;
    }
  }
  return h;
}

Array QuickSort::QuickSortRecursion(Array *arr, int start, int end, int numberOfRow) {
  int h = Separation(arr, start, end, numberOfRow);

  if (start < end) {
    QuickSortRecursion(arr, start, h, numberOfRow);
    QuickSortRecursion(arr, h + 1, end, numberOfRow);
  }

  return *arr;
}

Array QuickSort::Sort(Array arr) {
  for (int i = 0; i < arr.GetRow(); i++) {
    int start = 0;
    int end = arr.GetColumn();

    QuickSortRecursion(&arr, start, end, i);    
  }

  return arr;
}
  
