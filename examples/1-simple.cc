#include <hk/integer.h>

#include <iostream>

auto main() -> int {
  auto i = hk::integer{10};

  i += 15;

  if (i > 20) {
    std::cout << "Greater!\n";
  }

  if (i == 25) {
    std::cout << "Equal!\n";
  }

  std::cout << "Value: " << i.get() << "\n";
  std::cout << "sizeof(i) = " << sizeof(i) << "\n";

  return 0;
}
