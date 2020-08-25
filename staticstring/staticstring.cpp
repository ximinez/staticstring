// staticstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "jss.h"
#include <iostream>

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
	static auto a = jss::test.c_str();
	auto b = jss::test.c_str();
	std::cout << "a: " << (void*)a << " " << a << std::endl;
	std::cout << "b: " << (void*)b << " " << b << std::endl;
	EXPECT(strcmp(a, b) == 0);
	EXPECT(a == b);                        // fails
	EXPECT(a == jss::test.c_str());  // fails
	EXPECT(jss::test.c_str() == b);
	EXPECT(jss::test.c_str() == jss::test.c_str());
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
