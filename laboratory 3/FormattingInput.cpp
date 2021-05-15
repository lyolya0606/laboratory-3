#include <iostream>

using namespace std;

double GetDouble(void) {
  double input = 0;
  cin >> input;

  while (cin.fail()) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Input Error. Enter the number." << endl;
    cin >> input;
  }

  cin.ignore(INT_MAX, '\n');
  return input;
}

int GetInt(void) {
  int input = 0;
  cin >> input;

  while (cin.fail()) {
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    cout << "Input Error. Enter the number." << endl;
    cin >> input;
  }

  cin.ignore(INT_MAX, '\n');
  return input;
}