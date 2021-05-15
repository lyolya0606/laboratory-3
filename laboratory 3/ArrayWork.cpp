#include <iostream>
#include "FormattingInput.h"
#include "SavingFiles.h"
#include "ArrayClass.h"
#include "InputClass.h"
#include "Isort.h"
#include <iomanip>

using namespace std;

Input *ChoiceInput(int *result);

enum choiceInput {
  CHOICE_KEYBOARD = 1,
  CHOICE_RANDOM,
  CHOICE_FILE
};

void ArrayWork(void) {
  int result = 0;
  Input *input = ChoiceInput(&result);
  Array arr = input->Read();
  delete input;

  cout << endl << "Bubble sort:" << endl;
  BubbleSort bubbleSort;
  Array arrBubbleSort = bubbleSort.Sort(arr);
  arrBubbleSort.Print();

  cout << endl << "Selection sort:" << endl;
  SelectionSort selectionSort;
  Array arrSelectionSort = selectionSort.Sort(arr);
  arrSelectionSort.Print();

  cout << endl << "Insertion sort:" << endl;
  InsertionSort insertionSort;
  Array arrInsertionSort = insertionSort.Sort(arr);
  arrInsertionSort.Print();

  cout << endl << "Shell sort:" << endl;
  ShellSort shellSort;
  Array arrShellSort = shellSort.Sort(arr);
  arrShellSort.Print();

  cout << endl << "Quick sort:" << endl;
  QuickSort quickSort;
  Array arrQuickSort = quickSort.Sort(arr);
  arrQuickSort.Print();

  cout << endl << setw(30) << "comparisons" << setw(20) << "permutations" << endl
    << "Bubble sort:" << setw(13) << bubbleSort.GetComparison() << setw(19) << bubbleSort.GetPermutation() << endl
    << "Selection sort:" << setw(10) << selectionSort.GetComparison() << setw(19) << selectionSort.GetPermutation() << endl
    << "Insertion sort:" << setw(10) << insertionSort.GetComparison() << setw(19) << insertionSort.GetPermutation() << endl
    << "Shell sort:" << setw(14) << shellSort.GetComparison() << setw(19) << shellSort.GetPermutation() << endl
    << "Quick sort:" << setw(14) << quickSort.GetComparison() << setw(19) << quickSort.GetPermutation() << endl;
  
  if (result == CHOICE_KEYBOARD || result == CHOICE_RANDOM) {
    Array arrSaving = SavingFilesInput(move(arr));
    SavingFilesResult(move(arrSaving));
  } else {
    Array arrSaving = SavingFilesResult(move(arrSaving));
  }  
}