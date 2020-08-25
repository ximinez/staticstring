// staticstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr char const *const test = "test";

namespace detail {

	template<class Condition, class String>
	bool
		expect(Condition const& shouldBeTrue,
			String const& test,
			char const* file, int line)
	{
		std::cout << (shouldBeTrue ? "passed" : "FAILED") <<
			" at " << file << "(" << line << "): " << test << std::endl;
		return shouldBeTrue;
	}

} // detail

#define EXPECT(cond) detail::expect(cond, #cond, __FILE__, __LINE__)

int main()
{
  static auto a = test;
  auto b = test;
  std::cout << "a: " << (void *)a << " " << a << std::endl;
  std::cout << "b: " << (void *)b << " " << b << std::endl;
  EXPECT(strcmp(a, b) == 0);
  EXPECT(a == b);    // fails
  EXPECT(a == test); // fails
  EXPECT(test == b);
  EXPECT(test == test);
}
