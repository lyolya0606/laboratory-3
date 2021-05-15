#include <iostream>
#include <string>
#include <fstream>
#include "FormattingInput.h"
#include "ArrayClass.h"
#include "Isort.h"
#include <iomanip>

using namespace std;

ofstream OpenFileOutput(void);

Array SavingFilesInput(Array arr) {
  int row = arr.GetRow();;
  int column = arr.GetColumn();
  cout << endl << "Press 1 if you want to save your input in the file" << endl
    << "Press 2 if you DON'T want to save your input in the file" << endl;
  int choice = GetInt();
  const int SAVING = 1;
  const int NOT_SAVING = 2;

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    file << row << endl;
    file << column << endl;

    for (int i = 0; i < row; i++) {
      
      for (int j = 0; j < column; j++) {
        file << arr[i][j] << endl;
      }
    }

    file.close();
    cout << "Your input is successfully saved!" << endl;
  } else if (choice == NOT_SAVING) {
  }
  return arr;
}

Array SavingFilesResult(Array arr) {
  int row = arr.GetRow();;
  int column = arr.GetColumn();

  const int SAVING = 1;
  const int NOT_SAVING = 2;

  cout << endl << "Press 1 if you want to save your result in the file" << endl
    << "Press 2 if you DON'T want to save your result in the file" << endl;
  int choice = GetInt();

  while (choice != SAVING && choice != NOT_SAVING) {
    cout << "There is no such choice!" << endl
      << "Press 1 if you want to save your input in the file" << endl
      << "Press 2 if you DON'T want to save your input in the file" << endl;

    choice = GetInt();
  }

  if (choice == SAVING) {
    ofstream file = OpenFileOutput();

    file << "Saved array:" << endl;
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arr[i][j] << "|";
      }
      file << endl;
    }

    file << endl << "Bubble sort:" << endl;
    BubbleSort bubbleSort;
    Array arrBubbleSort = bubbleSort.Sort(arr);
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arrBubbleSort[i][j] << "|";
      }
      file << endl;
    }

    file << endl << "Selection sort:" << endl;
    SelectionSort selectionSort;
    Array arrSelectionSort = selectionSort.Sort(arr);
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arrSelectionSort[i][j] << "|";
      }
      file << endl;
    }

    file << endl << "Insertion sort:" << endl;
    InsertionSort insertionSort;
    Array arrInsertionSort = insertionSort.Sort(arr);
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arrInsertionSort[i][j] << "|";
      }
      file << endl;
    }

    file << endl << "Shell sort:" << endl;
    ShellSort shellSort;
    Array arrShellSort = shellSort.Sort(arr);
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arrShellSort[i][j] << "|";
      }
      file << endl;
    }

    file << endl << "Quick sort:" << endl;
    QuickSort quickSort;
    Array arrQuickSort = quickSort.Sort(arr);
    for (int i = 0; i < row; i++) {

      for (int j = 0; j < column; j++) {
        file << right << setw(6) << arrQuickSort[i][j] << "|";
      }
      file << endl;
    }

    file << endl << setw(30) << "comparisons" << setw(20) << "permutations" << endl
      << "Bubble sort:" << setw(13) << bubbleSort.GetComparison() << setw(19) << bubbleSort.GetPermutation() << endl
      << "Selection sort:" << setw(10) << selectionSort.GetComparison() << setw(19) << selectionSort.GetPermutation() << endl
      << "Insertion sort:" << setw(10) << insertionSort.GetComparison() << setw(19) << insertionSort.GetPermutation() << endl
      << "Shell sort:" << setw(14) << shellSort.GetComparison() << setw(19) << shellSort.GetPermutation() << endl
      << "Quick sort:" << setw(14) << quickSort.GetComparison() << setw(19) << quickSort.GetPermutation() << endl;

    file.close();
    cout << "Your result is successfully saved!" << endl;
  }
  return arr;
}
