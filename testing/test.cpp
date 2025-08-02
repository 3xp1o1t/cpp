#define FMT_HEADER_ONLY
#include <algorithm>
#include <cstddef>
#include <fmt/core.h>
#include <iostream>
#include <iterator>
#include <vector>
template <typename T>

std::ostream &operator<<(std::ostream &s,
                         const std::vector<std::vector<T>> &triangle) {
  for (const auto &row : triangle) {
    std::ranges::copy(row, std::ostream_iterator<T>(s, " "));
    s << '\n';
  }
  return s;
}

void show_vectors(std::ostream &s, const std::vector<std::vector<int>> &v) {
  size_t final_row_size = v.back().size();
  std::string spaces(final_row_size * 3, ' ');
  for (const auto &row : v) {
    s << spaces;

    if (spaces.size() > 3)
      spaces.resize(spaces.size() - 3);

    for (const auto &data : row) {
      s << fmt::v11::format("{: ^{}}", data, 6);
    }
    s << '\n';
  }
}

std::vector<int> get_next_row(const std::vector<int> &last_row) {
  std::vector next_row{1};
  if (last_row.empty()) {
    return next_row;
  }

  for (size_t idx = 0; idx + 1 < last_row.size(); ++idx) {
    next_row.emplace_back(last_row[idx] + last_row[idx + 1]);
  }
  next_row.emplace_back(1);
  return next_row;
}

auto generate_triangle(int rows) {
  std::vector<std::vector<int>> triangle{{1}};
  for (int row = 1; row < rows; ++row) {
    triangle.push_back(get_next_row(triangle.back()));
  }
  return triangle;
}

int main() {
  auto triangle = generate_triangle(15);
  show_vectors(std::cout, triangle);
}
