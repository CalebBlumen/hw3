#include <vector>
#include <stdexcept>
#include <iostream>

#include "heap.h"

using namespace std;

int main() {
  try {
    Heap<int> heap1;

    int data[5] = {2,5,6,3,7};

    cout << "Empty? (yes) " << heap1.empty() << endl;
    cout << "Size? (0) " << heap1.size() << endl;
    
    cout << "Pushing test" << endl;
    for (int i = 0; i < 5; ++i) {
      heap1.push(data[i]);
    }

    cout << "Size? (5) " << heap1.size() << endl;

    cout << "Top: " << heap1.top() << endl;

    cout << "Popping test" << endl;
    heap1.pop();

    cout << "New top: " << heap1.top() << endl;

    cout << "Empty? (no) " << heap1.empty() << endl;


  }
  catch(std::runtime_error& e) {
    cout << "Error: " << e.what() << endl;
  }
}