Requirements for custom iterators

1. Type aliases

- value_type: Type of the element the iterator points to.
- difference_type: Represents distance btw 2 iterators.
- pointer and reference: Iterator pointer and reference types.
- iterator_category: Input, Output, forward, bidireccional or random access, each category has its unique characteristics.

2. Operators:

- operator\*: The dereference operator, granting access to the element your iterator points to.
- operator++: The increment operators, These move iterator forward(either in pre-increment or post-increment style)
- operator== and operator!=: To compare iterators, letting algorithms know if they've reached the end or need to keep goind.

- Input iterators: Are read-only. They can move forward and read elements.

  - Essential: operator\*, operator++, operator==, operator!=

- Output iterators: Are write-only. Move forward and write elements.

  - Essential: operator\*, operator++

- Forward iterators: Combine Input and Output iterators, reading, writing and ALWAYS moving forward.

  - Essential: ALL

- Bidirectional iterators: They can move forwards and backwards, reading and writing.

  - Additional: operator-- -> to step back

- Random access iterators: They can leap to any position, they can read from and write to any position. They are perfect for random access data structures like STD:VECTOR

  - Additional: operator+,operator-,operator+=,operator-=,operator[] and relational operators such as operator<, operator<=, operator>, operator>=.
    This iterators are so powerful but it requieres a lot of functions to work correctly.
    Page 42 - C++ STL
