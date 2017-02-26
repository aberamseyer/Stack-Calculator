/*
 *
 * Simulation for the Stack implemenation as a calculator.
 * Main Driver file for the program.
 *
 * @author
 *
 */
#include "Stack.h"
#include <string>
#include <regex>

bool interpret(std::string& toCheck, Stack& totalStack, Stack& undoStack, int runningTotal, bool repeat);
void calculate(int runningTotal, std::string& toCheck);
void redo(Stack& totalStack, Stack& undoStack);
void undo(Stack& totalStack, Stack& undoStack);

int main() {

  Stack undoStack;
  Stack totalStack;
  int runningTotal = 0;
  bool repeat = true;
  std::string entry;
  std::regex number("[[:digit:]]+");
  std::regex command("[QURCqurc]");

  std::cout << "Welcome to this stack-based integer calculator. It works on a running total.\n\n" <<
                "Usage                   Function\n" <<
                "(operator)(number)      +, -, *, /, % the number to the total. i.e., +300, -12, /15, %60, etc.\n" <<
                "C                       Clears the total\n" <<
                "U                       Undo\n" <<
                "R                       Redo\n" <<
                "Q                       Quit" << std::endl;
  do {
    std::cout << ">";
    std::cin >> entry;
    if(!(std::regex_match(entry.substr(1), number) || std::regex_match(entry, command))) {  // determine number or command
      std::cout << "Invalid Input" << std::endl;
    } else {
      repeat = interpret(entry, totalStack, undoStack, runningTotal, repeat);
    }
    std::cout << runningTotal << std::endl;
  } while(repeat);

  return 0;
}

bool interpret(std::string& toCheck, Stack& totalStack, Stack& undoStack, int runningTotal, bool repeat) {
  switch (toCheck[0]) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      calculate(runningTotal, toCheck);
      undoStack.push(toCheck);
      break;
    case 'R':
    case 'r':
      redo(totalStack, undoStack);
      break;
    case 'U':
    case 'u':
      undo(totalStack, undoStack);
      break;
    case 'C':
    case 'c':
      totalStack.clear();
      undoStack.clear();
      break;
    case 'Q':
    case 'q':
      repeat = false;
      break;
    default:
      std::cout << "Invalid Input" << std::endl;
  }

  return repeat;
}

void calculate(int runningTotal, std::string& toCheck) {
  if(toCheck[0] == '+')
    runningTotal += std::stoi(toCheck.substr(1));
  else if(toCheck[0] == '-')
    runningTotal -= std::stoi(toCheck.substr(1));
  else if(toCheck[0] == '*')
    runningTotal *= std::stoi(toCheck.substr(1));
  else if(toCheck[0] == '/')
    runningTotal /= std::stoi(toCheck.substr(1));
  else if(toCheck[0] == '%')
    runningTotal %= std::stoi(toCheck.substr(1));
}

void redo(Stack& undoStack, Stack& redoStack) {
  undoStack.pop(); //TODO make this work
}

void undo(Stack& totalStack, Stack& undoStack) {
  totalStack.pop(); //TODO make this work
}
