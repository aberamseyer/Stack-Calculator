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
bool isNumber(const std::string& entry);

Stack redoStack;    // holds all the values that can be "re-done"
Stack undoStack;    // holds all the values that can be "un-done"
int runningTotal = 0; // the total displayed to the user after every iteration
bool repeat = true;   // whether the program should loop again or quit

int main() {
  std::string entry;
  std::regex command("[QURCqurc]", std::regex_constants::basic);     // matches the set of commands available

  std::cout << "Welcome to this stack-based integer calculator. It works on a running total.\n\n" <<
                "Usage                   Function\n" <<
                "(operator)(number)      +, -, *, /, % the number to the total. i.e., +300, -12, /15, %60, etc.\n" <<
                "C                       Clears the total\n" <<
                "U                       Undo\n" <<
                "R                       Redo\n" <<
                "Q                       Quit" << std::endl << std::endl << "total: " << runningTotal << std::endl;
  do {
    std::cout << std::endl << ">";
    std::cin >> entry;
   // std::locale loc;
    if(!(isNumber(entry.substr(1)) || std::regex_match(entry, command))) {  // determine whether a valid entry
      std::cout << "Invalid Input!" << std::endl;
    } else {
      interpret(entry);     // interpret command/number entered
    }
    std::cout << "total: " << runningTotal << std::endl;
  } while(repeat);

  std::cout << "\nGoodbye" << std::endl;
  return 0;
}

/*
 * takes the string the user entered
 */
void interpret(std::string& toCheck) {
  // further check to ensure the symbol entered is correct (wasn't working via regex)
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
      std::cout << "Invalid Input!" << std::endl;    // if the beginning symbol doesn't match, the input was invalid
  }

}

/*
 * takes the string the user entered
 */
void calculate(std::string& toCheck) {
  int number = std::stoi(toCheck.substr(1));
  undoStack.push(runningTotal);  // push the current runningTotal onto the stack

  // adjust runningTotal accordingly
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

  redoStack.clear();        // nothing to redo if a calculation goes through
}

/*
 * when clear is entered, 0 should become the new runningTotal with the previous value
 * going onto the undo stack
 */
void clear() {
  undoStack.push(runningTotal);
  runningTotal = 0;
  redoStack.clear();
}
/*
 * to redo, put the runningTotal onto the undoStack, set runningTotal
 * to the top of the redoStack, pop off that value
 */
void redo() {
  if(!redoStack.empty()) {
    undoStack.push(runningTotal);
    runningTotal = redoStack.top();
    redoStack.pop();
  }
  else {  // if the stacks are empty, nothing to redo
    std::cout << "Nothing to redo" << std::endl;
  }
}

/*
 * this should be the exact opposite of the redo() function with the stacks switched
 */
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

/*
 * checks if a given string is a number (because our regex only worked on our machines and not the school's linux machines)
 */
bool isNumber(const std::string& entry)
{
    std::string::const_iterator it = entry.begin();
    while (it != entry.end() && std::isdigit(*it)) ++it;
    return !entry.empty() && it == entry.end();
}
