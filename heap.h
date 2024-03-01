#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapVec;
  int m;
  PComparator comp;
  void swap(size_t idx1, size_t idx2);
};

// Add implementation of member functions here
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m(m), comp(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap(){}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  // trickleUp algorithm
  heapVec.push_back(item);
  size_t index = size() - 1;
  while (index != 0) {
      size_t parent_index = (index - 1) / m;
      if (comp(heapVec[parent_index],heapVec[index])) {
          break;
      }
      swap(index, parent_index);
      index = parent_index;
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {
  return heapVec.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {
  return heapVec.size();
}


// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  if(empty()){
    throw std::underflow_error("topped empty list");
  }
  
  return heapVec[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    throw std::underflow_error("topped empty list");
  }
  // trickleDown algorithm
  std::size_t index = 0;
  swap(0, size()-1);
  heapVec.pop_back();
  if (size() == 0) {
      return;
  }
  while (index != size()-1) {
      // if leftmost child doesn't exist, we are in the last position
      size_t left = index*m+1;
      if (left > size()-1) {
        break;
      }

      //find max/min/"most comp" child
      size_t most = left;
      for (int i = 1; i < m; ++i) {
        if (left+i == size()) {
          break;
        }
        if (comp(heapVec[left+i], heapVec[most])) {
          most = left+i;
        }
      }
      if (comp(heapVec[index], heapVec[most])) {
        break;
      }
      swap(index, most);
      index = most;
  }
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::swap(size_t idx1, size_t idx2) {
  T temp = heapVec[idx1];
  heapVec[idx1] = heapVec[idx2];
  heapVec[idx2] = temp;
}



#endif

