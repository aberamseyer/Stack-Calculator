/*
 *
 * Simulation for the Stack implemenation as a calculator.
 * Main Driver file for the program.
 *
 * @author Abe Ramseyer
 *
 */
#include "Stack.h"
#include <string>
#include <regex>

void interpret(std::string& toCheck);
void calculate(std::string& toCheck);
void clear(std::string& toCheck);
void redo();
void undo();

Stack undoStack;
Stack totalStack;
int runningTotal = 0;
bool repeat = true;

int main() {
  std::string entry;
  std::regex number("[[:digit:]]+");
  std::regex command("[QURCqurc]");

  std::cout << "Welcome to this stack-based integer calculator. It works on a running total.\n\n" <<
                "Usage                   Function\n" <<
                "(operator)(number)      +, -, *, /, % the number to the total. i.e., +300, -12, /15, %60, etc.\n" <<
                "C                       Clears the total\n" <<
                "U                       Undo\n" <<
                "R                       Redo\n" <<
                "Q                       Quit" << std::endl << std::endl << "0" << std::endl;
  do {
    std::cout << ">";
    std::cin >> entry;
    if(!(std::regex_match(entry.substr(1), number) || std::regex_match(entry, command))) {  // determine number or command
      std::cout << "Invalid Input" << std::endl;
    } else {
      interpret(entry);
    }
    std::cout << runningTotal << std::endl;
  } while(repeat);

  return 0;
}

void interpret(std::string& toCheck) {
  int number;
  switch (toCheck[0]) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      calculate(toCheck);   // calculates the runningTotal with the new number
      break;
    case 'R':
    case 'r':
      redo();
      break;
    case 'U':
    case 'u':
      undo();
      break;
    case 'C':
    case 'c':
      clear(toCheck);
      break;
    case 'Q':
    case 'q':
      repeat = false;
      break;
    default:
      std::cout << "Invalid Input" << std::endl;
  }

}

void calculate(std::string& toCheck) {
  int number = std::stoi(toCheck);

  if(toCheck[0] == '+')
    runningTotal += number;
  else if(toCheck[0] == '-')
    runningTotal -= number;
  else if(toCheck[0] == '*')
    runningTotal *= number;
  else if(toCheck[0] == '/')
    runningTotal /= number;
  else if(toCheck[0] == '%')
    runningTotal %= number;

  totalStack.push(number);  // push the current runningTotal onto the stack
  undoStack.clear();        // nothing to redo if a calculation goes through
}

void clear(std::string& toCheck) {
  int number = std::stoi(toCheck);
  totalStack.push(number);
  runningTotal = 0; // zero
}

void redo() {
  if(!undoStack.empty()) {
    totalStack.push(runningTotal);
    runningTotal = undoStack.top();
    undoStack.pop();
    undoStack.clear();
  }
  else {
    std::cout << "Nothing to redo" << std::endl;
  }
}

void undo() {
  if(!totalStack.empty()) {
    undoStack.push(runningTotal);
    runningTotal = totalStack.top();
    totalStack.pop();
  }
  else {
    std::cout << "Nothing to undo" << std::endl;
  }
}
