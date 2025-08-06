#include <iostream>
#include <vector>

int main() {
  // Popular function from vector
  // https://www.w3schools.com/cpp/cpp_ref_vector.asp
  std::vector<int> numbers = {10, 20, 30, 40, 50};

  // Print vector elements
  for (int n : numbers) {
    std::cout << n << ' ';
  }
  std::cout << "\n";

  // Access element by index (insecure) vs helper functions
  std::cout << "Access via Index: " << numbers[0] << "\n"; // index
  std::cout << "Access via front(): " << numbers.front()
            << "\n"; // first element
  std::cout << "Access via back(): " << numbers.back();
  std::cout << "\n";

  std::cout << "Access to specific element at(): " << numbers.at(3) << "\n";

  // It is posible to do it with at()
  numbers[0] = 100;
  std::cout << "Change value from vector using index []: " << numbers.front()
            << "\n";

  numbers.push_back(60);
  numbers.push_back(70);
  std::cout << "Adding values to vector using push_back(): " << numbers.back()
            << "\n";

  numbers.pop_back();
  std::cout << "Removing elements from vector using pop_back(): "
            << numbers.back() << "\n";

  std::cout << "Size of a vector with size(): " << numbers.size() << "\n";
  std::cout << "Check if vector is empty with empty(): " << numbers.empty()
            << "\n";

  std::cout << "Looping throug a vector using normal for" << "\n";
  for (size_t i = 0; i < numbers.size(); i++) {
    std::cout << numbers[i] << " ";
  }
  std::cout << "\n";

  return 0;
}
