#include <iostream>
#include "Isort.h"
#include "ArrayClass.h"
#include "FormattingInput.h"
#include "Beginning.h"

using namespace std;

void ArrayWork(void);
void Test(void);

enum actionWithArray {
  ARRAY_WORK = 1,
  ARRAY_TEST
};

enum endOfProgram {
  QUIT = 1,
  CONTINUE
};


int main() {
  Greeting();
  int userChoice = 0;
  bool stop;

  do {
    do {
      Menu();
      userChoice = GetInt();

      switch (userChoice) {

      case ARRAY_WORK:
        ArrayWork();
        stop = true;
        break;

      case ARRAY_TEST:
        Test();
        stop = true;
        break;

      default:
        cout << "There is no such choice!" << endl;
        stop = false;
      }

    } while (stop == false);

    do {
      cout << endl << "Press 1 to finish" << endl;
      cout << "Press 2 to continue" << endl;
      userChoice = GetInt();

      if (userChoice != QUIT && userChoice != CONTINUE) {
        cout << "There is no such choice!" << endl;
      }
    } while (userChoice != QUIT && userChoice != CONTINUE);

  } while (userChoice != QUIT);

  return 0;
}