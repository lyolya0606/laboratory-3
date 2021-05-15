#include <iostream>
#include "FormattingInput.h"
#include "Beginning.h"
#include <string>
#include <fstream>
#include <ctime>
#include "ArrayClass.h"
#include "InputClass.h"

using namespace std;

ifstream OpenFileInput(void);

enum choiceInput {
  CHOICE_KEYBOARD = 1,
  CHOICE_RANDOM,
  CHOICE_FILE
};

Array KeyboardInput::Read() {
  int row = 0;
  int column = 0;

  do {

    cout << "Enter the array size:" << endl;
    cout << "Number of rows: ";
    row = GetInt();
    cout << "Number of columns: ";
    column = GetInt();

    if (row <= 0 || column <= 0) {
      cout << "The array size cannot be less than one!" << endl;
    }
  } while (row <= 0 || column <= 0);

  Array arr(row, column);

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      cout << "Enter element " << "[" << i + 1 << "][" << j + 1 << "]  ";
      arr[i][j] = GetDouble();
    }
  }

  cout << endl << "The array:" << endl;
  arr.Print();
  return arr;

}

Array RandomInput::Read() {
  int row = 0;
  int column = 0;
  srand(static_cast<unsigned int>(time(NULL)));
  const double LEFT_BOARDER = -100.0;
  const double RIGHT_BOARDER = 100.0;

  do {

    cout << "Enter the array size:" << endl;
    cout << "Number of rows: ";
    row = GetInt();
    cout << "Number of columns: ";
    column = GetInt();

    if (row <= 0 || column <= 0) {
      cout << "The array size cannot be less than one!" << endl;
    }
  } while (row <= 0 || column <= 0);

  Array arr(row, column);
  double tmp;

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++) {
      tmp = LEFT_BOARDER + (RIGHT_BOARDER - LEFT_BOARDER) * rand() / (static_cast<double>(RAND_MAX));
      arr[i][j] = (int)(tmp * 100) / 100.0;
    }
  }

  cout << endl << "The array:" << endl;
  arr.Print();

  return arr;
}

Array FileInput::Read() {
  int row = 0;
  int column = 0;
  string path;
  string line;
  int checkingSize = 0;
  bool checkingData = true;
  ifstream file;

  do {

    do {
      file = OpenFileInput();
      checkingSize = 0;
      try {
        getline(file, line);
        row = stoi(line);
        getline(file, line);
        column = stoi(line);

        if (row <= 0 || column <= 0) {
          throw 1;
        }
        checkingData = true;
      }
      catch (invalid_argument size) {
        cout << "Incorrect data in the file! Try again." << endl;
        checkingData = false;

      }
      catch (int negativeSize) {
        if (negativeSize == 1) {
          checkingSize++;
          cout << "Incorrect data in the file! Try again." << endl;
        }
      }

    } while (checkingSize != 0 || checkingData == false);

    if (checkingSize == 0) {

      Array arr(row, column);

      try {

        for (int i = 0; i < row; i++) {

          for (int j = 0; j < column; j++) {
            getline(file, line);
            arr[i][j] = stod(line);
          }
        }

        checkingData = true;
      }

      catch (invalid_argument arrFilled) {
        cout << "Incorrect data in the file! Try again." << endl;
        checkingData = false;
      }

      if (checkingData == true) {
        cout << "Read data:" << endl;
        arr.Print();
        return arr;
      }

    }
  } while (checkingData == false);

  string invArg = "Went out of the loop";
  throw invArg;
}

Input *ChoiceInput(int *result) {
  int choice = 0;

  do {
    MenuWorkArray();
    choice = GetInt();

    switch (choice) {

    case CHOICE_KEYBOARD:
    {
      KeyboardInput *keyboardInput = new KeyboardInput;
      (*result) = CHOICE_KEYBOARD;
      return keyboardInput;
    }

    case CHOICE_RANDOM:
    {
      RandomInput *randomInput = new RandomInput;
      (*result) = CHOICE_RANDOM;
      return randomInput;
    }

    case CHOICE_FILE:
    {
      FileInput *fileInput = new FileInput;
      (*result) = CHOICE_FILE;
      return fileInput;
    }

    default:
      cout << "There is no such choice!" << endl;
      (*result) = 0;
      break;
    }
  } while (true);
}

