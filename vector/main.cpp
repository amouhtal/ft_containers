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

	ft::vector<int> vec;

	vec.push_back(7);
	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(5);

	ft::vector<int> vec2;

	vec2.push_back(25);
	vec2.push_back(23);
	// vec2.push_back(24);
	// vec2.push_back(28);
	// vec2.push_back(20);

	ft::vector<int>::iterator bg;
	ft::vector<int>::iterator ed;

	bg = vec2.begin();
	ed = vec2.end();
	try
	{
		vec.assign(ed, bg);
		/* code */
	}
	catch ( const char *str)
	{
		std::cerr << str << '\n';
	}

	ft::vector<int>::iterator it;

	for (it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << "it: " << *it << std::endl;
	}

	// // std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// // vec.push_back(6);
	// std::cout << vec[4] << std::endl;

	// std::cout << "_capacity : " << vec[3] << " _size : " << vec.size() << std::endl;
	// vec.reserve(5);

	/*
	1 = capacity : 2 _size : 1
	3 =  _capacity : 4 _size : 3
*/

	/*
	ft::vector<int>::iterator it;
	const int i = 0;
	vec.at(i) = 99;
	int val = vec.at(i);
	val = vec.back();
	// it = vec.at(2);
	// for (it = vec.begin(); it!= vec.end(); it++)
	// {
	std::cout << "it: " << val << std::endl;
	// i++;
	// }
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// ft::vector<int>::iterator it = vec.begin();
	// std::vector<int>::iterator ite = vec.end();

	// std::cout << *it << std::endl;
*/
	return 0;
}