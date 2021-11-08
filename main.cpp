// lexicographical_compare example
#include <iostream>	 // std::cout, std::boolalpha
#include <algorithm> // std::lexicographical_compare
#include <cctype>	 // std::tolower
#include "vector.hpp"
#include "reverse_iterator.hpp"

#include <vector>
// a case-insensitive comparison function:
bool mycomp(char c1, char c2)
{
	return std::tolower(c1) < std::tolower(c2);
}

int main()
{

	std::vector<int> vec;
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	// std::cout << *it << std::endl;
	it.operator->;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}
	// it++;
	// std::cout << *it << std::endl;
	// int *p = it.base();

	// *p = 150;
	// std::vector<int>::iterator ite = vec.begin();

	// std::cout << *ite << std::endl;
	// std::vector<int>::reverse_iterator rit;

	// rit = vec.begin();

	// rit
	// while ()
	// {
	// 	/* code */
	// }

	return 0;
}