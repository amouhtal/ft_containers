// #include "vector.hpp"

#include <vector>
#include <map>
#include <iostream>
template <class T, class = typename std::enable_if<std::is_unsigned<T>::value>::type>
void foo(T)
{
	std::cout << "Is unsigned\n";
};

int main()
{
	unsigned int nbr = 200;
	char c = 32;

	foo(nbr);
	/*
	std::map<int, std::string> numbers;
	numbers.insert(std::make_pair(1, "one"));
	numbers.insert(std::make_pair(2, "two"));
	numbers.insert(std::make_pair(3, "three"));

	typedef std::map<int, std::string>::iterator map_iter;

	std::reverse_iterator<map_iter> rev_end(numbers.begin());

	std::reverse_iterator<map_iter> rev_iterator(numbers.end());

	for (; rev_iterator != rev_end; ++rev_iterator)
		std::cout << rev_iterator->first << ' ' << rev_iterator->second << '\n';*/
}