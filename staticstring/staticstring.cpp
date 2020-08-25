// staticstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr char const *const test = "test";

int main()
{
  static auto a = test;
  auto b = test;
  std::cout << "a: " << (void *)a << " " << a << std::endl;
  std::cout << "b: " << (void *)b << " " << b << std::endl;

  std::cout << "a and b represent the same string: "
            << (strcmp(a, b) == 0 ? "yes" : "***NO***") << std::endl;
  std::cout << "a and b have the same address: "
            << (a == b ? "yes" : "***NO***"); // fails
}
