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

	vec.push_back(7);
	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(7);
	vec.push_back(7);
	
	// vec.push_back(6);
	vec.reserve(5);
	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

/*
	1 = capacity : 2 _size : 1
	3 =  _capacity : 4 _size : 3
*/

	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;


	// std::vector<int>::iterator it;
	// for (it = vec.begin(); it!= vec.end(); it++)
	// {
	// 	std::cout << "it: " << *it << std::endl;
	// }
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	
	// ft::vector<int>::iterator it = vec.begin();
	// std::vector<int>::iterator ite = vec.end();

	// std::cout << *it << std::endl;

	return 0;
}