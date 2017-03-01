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
void clear();
void redo();
void undo();

Stack redoStack;
Stack undoStack;
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
                "Q                       Quit" << std::endl << std::endl << std::endl;
  do {
    // std::cout << "undo stack: ";
    // undoStack.printStack();
    // std::cout << std::endl << "redo stack: ";
    // redoStack.printStack();
    std::cout << std::endl << ">";
    std::cin >> entry;
    if(!(std::regex_match(entry.substr(1), number) || std::regex_match(entry, command))) {  // determine number or command
      std::cout << "Invalid Input" << std::endl;
    } else {
      interpret(entry);
    }
    std::cout << "total: " << runningTotal << std::endl;
  } while(repeat);

  return 0;
}

void interpret(std::string& toCheck) {
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
      clear();
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
  int number = std::stoi(toCheck.substr(1));

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

  undoStack.push(runningTotal);  // push the current runningTotal onto the stack
  redoStack.clear();        // nothing to redo if a calculation goes through
}

void clear() {
  undoStack.push(runningTotal);
  runningTotal = 0; // zero
}

void redo() {
  if(!redoStack.empty()) {
    undoStack.push(runningTotal);
    runningTotal = redoStack.top();
    redoStack.pop();
    // redoStack.clear();
  }
  else {
    std::cout << "Nothing to redo" << std::endl;
  }
}

void undo() {
  if(!undoStack.empty()) {
    redoStack.push(runningTotal);
    runningTotal = undoStack.top();
    undoStack.pop();
  }
  else {
    std::cout << "Nothing to undo" << std::endl;
  }
}
