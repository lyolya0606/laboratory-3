#include <iostream>
#include <cmath>
#include "ArrayClass.h"
#include "Isort.h"

using namespace std;

const int ALL_TEST_PASSED = 5;

enum IncorrectSorting {
  ARR_BUBBLE_SORT,
  ARR_SELECTION_SORT,
  ARR_INSERTION_SORT,
  ARR_SHELL_SORT
};

bool TestingProgram(Array enteredArr, Array expectedArr, int numberOfTest) {
  BubbleSort bubbleSort;
  Array arrBubbleSort = bubbleSort.Sort(enteredArr);

  SelectionSort selectionSort;
  Array arrSelectionSort = selectionSort.Sort(enteredArr);

  InsertionSort insertionSort;
  Array arrInsertionSort = insertionSort.Sort(enteredArr);

  ShellSort shellSort;
  Array arrShellSort = shellSort.Sort(enteredArr);

  QuickSort quickSort;
  Array arrQuickSort = quickSort.Sort(enteredArr);
  
  try {

    for (int i = 0; i < enteredArr.GetRow(); i++) {
      for (int j = 0; j < enteredArr.GetColumn(); j++) {

        if (fabs(arrBubbleSort[i][j]) != fabs(arrSelectionSort[i][j])) throw ARR_BUBBLE_SORT;
        if (fabs(arrSelectionSort[i][j]) != fabs(arrInsertionSort[i][j])) throw ARR_SELECTION_SORT;
        if (fabs(arrInsertionSort[i][j]) != fabs(arrShellSort[i][j])) throw ARR_INSERTION_SORT;
        if (fabs(arrShellSort[i][j]) != fabs(arrQuickSort[i][j])) throw ARR_SHELL_SORT;
        if (fabs(arrQuickSort[i][j]) != fabs(expectedArr[i][j])) throw i;

      }
    }

    return true;

  } catch (IncorrectSorting incorrectSorting) {

    if (incorrectSorting == ARR_BUBBLE_SORT) {
      cout << endl << "Test " << numberOfTest + 1 << " faild" << endl
        << "Bubble sort" << endl;
      arrBubbleSort.Print();
    }

    if (incorrectSorting == ARR_SELECTION_SORT) {
      cout << endl << "Test " << numberOfTest + 1 << " faild" << endl
        << "Selection sort" << endl;
      arrSelectionSort.Print();
    }

    if (incorrectSorting == ARR_INSERTION_SORT) {
      cout << endl << "Test " << numberOfTest + 1 << " faild" << endl
        << "Insertion sort" << endl;
      arrInsertionSort.Print();
    }

    if (incorrectSorting == ARR_SHELL_SORT) {
      cout << endl << "Test " << numberOfTest + 1 << " faild" << endl
       << "Shell Sort " << endl;
      arrShellSort.Print();
    }

  } catch (int rowValue) {
    cout << endl << "Test" << numberOfTest + 1 << " failed. Mismatch found in " << rowValue + 1 << " row" << endl;
    cout << endl << "The array:" << endl;
    enteredArr.Print();

    cout << endl << "Expected output array:" << endl;
    expectedArr.Print();

    cout << endl << "Output array:" << endl;
    arrQuickSort.Print();

    return false;
  }

  return true;
}


void Test(void) {
  int numberOfTest = 0;
  const int rowTest1 = 3;
  const int columnTest1 = 5;
  double enteredDataTest1[rowTest1][columnTest1] = { {-22,  75,  61, -22, -53 },
  { 86, -32,  34,  41, -47 },
  {-86,  82,  95, -95,  78} };

  Array enteredArrTest1(rowTest1, columnTest1);

  for (int i = 0; i < rowTest1; i++) {
    for (int j = 0; j < columnTest1; j++) {
      enteredArrTest1[i][j] = enteredDataTest1[i][j];
    }
  }

  
  double expectedResultTest1[rowTest1][columnTest1] = { {-22, -22, -53, 61, 75 },
  {-32, 34, 41, -47, 86 },
  {78, 82, -86, 95, -95 } };

  Array expectedArrTest1(rowTest1, columnTest1);

  for (int i = 0; i < rowTest1; i++) {
    for (int j = 0; j < columnTest1; j++) {
      expectedArrTest1[i][j] = expectedResultTest1[i][j];
    }
  }

  
  if (TestingProgram(move(enteredArrTest1), move(expectedArrTest1), numberOfTest) == true) {
    numberOfTest++;
  }

  const int rowTest2 = 3;
  const int columnTest2 = 4;
  double enteredDataTest2[rowTest2][columnTest2] = { {6, -3,  0,  9 },
  { 8,  1,  0,  4 },
  { 9,  8,  2, -7 } };

  Array enteredArrTest2(rowTest2, columnTest2);

  for (int i = 0; i < rowTest2; i++) {
    for (int j = 0; j < columnTest2; j++) {
      enteredArrTest2[i][j] = enteredDataTest2[i][j];
    }
  }

  double expectedResultTest2[rowTest2][columnTest2] = { { 0, -3, 6, 9 },
  { 0, 1, 4, 8 },
  { 2, -7, 8, 9 } };

  Array expectedArrTest2(rowTest2, columnTest2);

  for (int i = 0; i < rowTest2; i++) {
    for (int j = 0; j < columnTest2; j++) {
      expectedArrTest2[i][j] = expectedResultTest2[i][j];
    }
  }

  if (TestingProgram(move(enteredArrTest2), move(expectedArrTest2), numberOfTest) == true) {
    numberOfTest++;
  }

  const int rowTest3 = 4;
  const int columnTest3 = 5;
  double enteredDataTest3[rowTest3][columnTest3] = { {-48,  98, -68,  65,  39 },
  { 91,  16, -89, -78,  35 },
  {-55,  38,  33, -39,  49 },
  { 11, -70, -34,  97,  91 } };

  Array enteredArrTest3(rowTest3, columnTest3);

  for (int i = 0; i < rowTest3; i++) {
    for (int j = 0; j < columnTest3; j++) {
      enteredArrTest3[i][j] = enteredDataTest3[i][j];
    }
  }

  double expectedResultTest3[rowTest3][columnTest3] = { { 39, -48, 65, -68, 98 },
  { 16, 35, -78, -89, 91 },
  { 33, 38, -39, 49, -55 },
  { 11, -34, -70, 91, 97 } };

  Array expectedArrTest3(rowTest3, columnTest3);

  for (int i = 0; i < rowTest3; i++) {
    for (int j = 0; j < columnTest3; j++) {
      expectedArrTest3[i][j] = expectedResultTest3[i][j];
    }
  }

  if (TestingProgram(move(enteredArrTest3), move(expectedArrTest3), numberOfTest) == true) {
    numberOfTest++;
  }

  const int rowTest4 = 2;
  const int columnTest4 = 6;
  double enteredDataTest4[rowTest4][columnTest4] = { { -6, -65,   4,  32,  23, -69 },
  { 42, -32, -16,  58,  78, -83 } };

  Array enteredArrTest4(rowTest4, columnTest4);

  for (int i = 0; i < rowTest4; i++) {
    for (int j = 0; j < columnTest4; j++) {
      enteredArrTest4[i][j] = enteredDataTest4[i][j];
    }
  }

  double expectedResultTest4[rowTest4][columnTest4] = { { 4, -6, 23, 32, -65, -69 },
  { -16, -32, 42, 58, 78, -83 } };

  Array expectedArrTest4(rowTest4, columnTest4);

  for (int i = 0; i < rowTest4; i++) {
    for (int j = 0; j < columnTest4; j++) {
      expectedArrTest4[i][j] = expectedResultTest4[i][j];
    }
  }

  if (TestingProgram(move(enteredArrTest4), move(expectedArrTest4), numberOfTest) == true) {
    numberOfTest++;
  }

  const int rowTest5 = 3;
  const int columnTest5 = 9;
  double enteredDataTest5[rowTest5][columnTest5] = { { -21, -19, 6, -36,  80,  28,  52,  41,  32 },
  { 60, -46,   8,  66, -59, -9,  70,  35,  18 },
  { -74,  48, -60,  25,  78,  72,  52,  98, -96 } };

  Array enteredArrTest5(rowTest5, columnTest5);

  for (int i = 0; i < rowTest5; i++) {
    for (int j = 0; j < columnTest5; j++) {
      enteredArrTest5[i][j] = enteredDataTest5[i][j];
    }
  }

  double expectedResultTest5[rowTest5][columnTest5] = { { 6, -19, -21, 28, 32, -36, 41, 52, 80 },
  { 8, -9, 18, 35, -46, -59, 60, 66, 70 },
  { 25, 48, 52, -60, 72, -74, 78, -96, 98 } };

  Array expectedArrTest5(rowTest5, columnTest5);

  for (int i = 0; i < rowTest5; i++) {
    for (int j = 0; j < columnTest5; j++) {
      expectedArrTest5[i][j] = expectedResultTest5[i][j];
    }
  }

  if (TestingProgram(move(enteredArrTest5), move(expectedArrTest5), numberOfTest) == true) {
    numberOfTest++;
  }

  if (numberOfTest == ALL_TEST_PASSED) {
    cout << endl << "All test passed successfully!" << endl;
  }
}