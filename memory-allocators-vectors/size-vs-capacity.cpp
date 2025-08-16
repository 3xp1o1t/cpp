// La diferencia entre size y capacity en un vector de C++ es que size() devuelve el número de elementos actualmente almacenados en el vector, mientras que capacity() devuelve la cantidad de memoria que ha sido reservada para el vector, que puede ser mayor o igual a size(). Esto significa que un vector puede tener espacio adicional reservado para nuevos elementos sin necesidad de realocar memoria.

#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec;

  std::cout << "Initial size: " << vec.size()
            << ", capacity: " << vec.capacity() << "\n";
  
  for (auto i = 0; i < 10; ++i) {
    vec.push_back(i);

    std::cout << "After adding " << i + 1 
              << ", integers, size: " << vec.size()
              << ", capacity: " << vec.capacity() << "\n";
  }

  // Mantiene la capacity nueva que se fue ajustando.
  vec.resize(5);
  std::cout << "After resizing to 5 elements, size: "
            << vec.size()
            << ", capacity: " << vec.capacity() << "\n";

  // Ajusta la capacity que se agrego durante la creacion de otros elementos
  vec.shrink_to_fit();
  std::cout << "After shrink_to_fit, size: "
            << vec.size()
            << ", capacity: " << vec.capacity() << "\n";
  
  vec.push_back(5);
  std::cout << "After adding one more element, size: "
            << vec.size()
            << ", capacity: " << vec.capacity() << "\n";
  
  return 0;
}