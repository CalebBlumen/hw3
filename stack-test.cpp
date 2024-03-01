#include <vector>
#include <stdexcept>
#include <iostream>

#include "stack.h"

using namespace std;

int main() {
  try {
  Stack<int> tStack;
  bool isEmpty = tStack.empty();

  cout << "Empty test (should be true): " << isEmpty << endl;

  int testList[5] = {1,2,3,4,5};

   cout << "Pushing: " << endl;
  
  for (int i = 0; i < 5; ++i) {
    tStack.push(testList[i]);
  }

  cout << "Top: " << tStack.top() << endl;

  cout << "Popping..." << endl;
  tStack.pop();

  cout << "New top: " << tStack.top() << endl;

  cout << endl << "Now trying empty:" << endl;
  Stack<char> tStack2;
  tStack2.top();
  } 
  catch (const std::runtime_error& e) {
    cout << "Error: " << e.what() << endl;
  }
}