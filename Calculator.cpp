/*
 *
 * Simulation for the Stack implemenation as a calculator.
 * Main Driver file for the program.
 *
 * @author
 *
 */
#include "Stack.h"

bool interpret(std::string& toCheck, Stack& totalStack, Stack& undoStack, bool repeat);
void encode(std::string& toCheck, Stack& totalStack);
void redo(Stack& totalStack, Stack& undoStack);
void undo(Stack& totalStack, Stack& undoStack);

int main() {

  Stack undoStack;
  Stack totalStack;

  bool repeat = true;
  std::string entry;
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
    repeat = interpret(entry, totalStack, undoStack, repeat);
  } while(repeat);


  return 0;
}

bool interpret(std::string& toCheck, Stack& totalStack, Stack& undoStack, bool repeat) {
  switch (toCheck[0]) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
      encode(toCheck, totalStack);
      break;
    case 'R':
    case 'r':
      //call to redo()
      break;
    case 'U':
    case 'u':
      //call to undo()
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
  }
  return repeat;
}

void encode(std::string& toCheck, Stack& totalStack) {
  switch (toCheck[0]) {
    case '+':
      (toCheck).replace(0, 1, std::string("1"));
      break;
    case '-':
      (toCheck).replace(0, 1, std::string("2"));
      break;
    case '*':
      (toCheck).replace(0, 1, std::string("3"));
      break;
    case '/':
      (toCheck).replace(0, 1, std::string("4"));
      break;
    case '%':
      (toCheck).replace(0, 1, std::string("5"));
      break;
    }
    totalStack.push(toCheck);
}

void redo(Stack& undoStack, Stack& redoStack) {
  undoStack.pop(); //TODO make this work
}

void undo(Stack& totalStack, Stack& undoStack) {
  totalStack.pop(); //TODO make this work
}
