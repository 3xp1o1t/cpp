#include <forward_list>
#include <iostream>

int main() {

  // It has both functionality of input and output iterators
  // It can be used to traverse a forward list in one direction (forward)
  // and can also be used to insert elements at the front of the list.
  std::forward_list<int> flist = {10,20,30,40,50};

  std::cout << "Original List: ";

  // Displaying the elements of the forward list Input Iterator
  for(auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";

  // Output Iterator functionality
  for(auto it = flist.begin(); it != flist.end(); ++it) {
    (*it)++;
  }

  std::cout << "Modified List: ";
  for(auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "\n";
  return 0;

}