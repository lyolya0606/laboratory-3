#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "FormattingInput.h"

using namespace std;

ofstream OpenFileOutput(void) {
  const int FILE_HAS_DATA = 0;
  const int OVERWRITE_FILE = 1;
  const int OVERWRITE_PATH = 2;

  bool pathIsCorrect;
  ofstream file;
  string path;

  do {
    int choice;
    ifstream existFile;

    cout << "Input the path to the file: ";
    getline(cin, path);
    file.open(path, ios::app);

    if (file.is_open()) {
      error_code ec;
      pathIsCorrect = true;

      if (!filesystem::is_regular_file(path, ec)) {
        cout << "Opening error! Try again." << endl;
        file.close();
        pathIsCorrect = false;
      }
      file.close();

    } else {
      cout << "Opening error! Try again." << endl;
      pathIsCorrect = false;
    }

    if (pathIsCorrect == true) {
      existFile.open(path);
      string line = "";
      string stringGeneral = "";

      while (!existFile.eof()) {
        getline(existFile, line);
        stringGeneral += line;
      }

      existFile.close();

      if (stringGeneral.length() != FILE_HAS_DATA) {
        cout << "This file has some data. Do you want to overwrite the file?" << endl
          << "Press 1 if you want to overwrite this file" << endl
          << "Press 2 if you DON'T want to overwrite this file" << endl;

        choice = GetInt();

        while (choice != OVERWRITE_PATH && choice != OVERWRITE_FILE) {
          cout << "There is no such choice!" << endl
            << "Press 1 if you want to overwrite this file" << endl
            << "Press 2 if you DON'T want to overwrite this file" << endl;

          choice = GetInt();
        }

        if (choice == OVERWRITE_PATH) {
          pathIsCorrect = false;
        }

        if (choice == OVERWRITE_FILE) {
          pathIsCorrect = true;
        }

      }

      existFile.close();
    }

    if (pathIsCorrect == false) {
      file.close();
    }

  } while (pathIsCorrect == false);

  file.open(path);

  return file;
}

ifstream OpenFileInput(void) {
  const int FILE_HAS_DATA = 0;
  const int OVERWRITE_PATH = 1;

  bool patIsCorrect;
  ifstream file;
  string path;

  do {
    cout << "Input the path to the file: ";
    getline(cin, path);
    file.open(path);

    if (file.is_open()) {
      error_code ec;
      patIsCorrect = true;

      if (!filesystem::is_regular_file(path, ec)) {
        cout << "Opening error! Try again." << endl;
        file.close();
        patIsCorrect = false;
      }
      file.close();

    } else {
      cout << "Opening error! Try again." << endl;
      patIsCorrect = false;
    }

    if (patIsCorrect == false) {
      file.close();
    }

  } while (patIsCorrect == false);

  file.open(path);

  return file;
}
