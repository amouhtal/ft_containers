// lexicographical_compare example
#include <iostream>	 // std::cout, std::boolalpha
#include <algorithm> // std::lexicographical_compare
#include <cctype>	 // std::tolower
#include "vector.hpp"
#include "reverse_iterator.hpp"
#define s 6
#define n 4
#include <vector>

int main()
{

	ft::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);

	vec.push_back(7);
	vec.push_back(8);
	vec.push_back(9);


	ft::vector<int>::iterator it;
	ft::vector<int>::iterator it1;

	it = vec.begin();
	it++;
	it++;

	ft::vector<int> vec2;

	vec2.push_back(3);
	vec2.push_back(4);
	vec2.push_back(5);
	vec2.push_back(6);


	ft::vector<int>::iterator itt;
	ft::vector<int>::iterator itt1;

	itt = vec2.begin();

	itt1 = vec2.end();
	// it++;
	// int i = 0;
	// while ()
	// {
	// 	/* code */
	// }
	// vec.insert(it, 4);
	vec.insert(it, 4, 5);
	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	ft::vector<int>::iterator bg;
	ft::vector<int>::iterator ed;
	std::cout << "output" << std::endl;

	bg = vec.begin();
	ed = vec.end();
	for (; bg != ed; bg++)
	{
		std::cout << "it: " << *bg << std::endl;
	}

	// {
	// ft::vector<int> vec;

	// vec.push_back(s);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(n);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(9);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(7);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(5);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// vec.push_back(s);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(n);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(9);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(7);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// vec.push_back(5);
	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// // 	vec.push_back(s);
	// // 	vec.push_back(n);
	// // 	vec.push_back(9);
	// // 	vec.push_back(7);
	// // 	vec.push_back(5);
	// // 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// // 	vec.resize(n);

	// // 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// 	ft::vector<int>::iterator bg;
	// 	ft::vector<int>::iterator ed;
	// 	std::cout << "output" << std::endl;

	// 	bg = vec.begin();
	// 	ed = vec.end();
	// 	for (; bg != ed; bg++)
	// 	{
	// 		std::cout << "it: " << *bg << std::endl;
	// 	}
	// }
	// std::cout << "------------" << std::endl;
	// {
	// 	std::vector<int> vec;

	// 	vec.push_back(s);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(n);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(9);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(7);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(5);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// 	vec.push_back(s);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(n);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(9);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(7);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	vec.push_back(5);
	// 	std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;
	// 	// vec.resize(n);

	// 	// std::cout << "_capacity : " << vec.capacity() << " _size : " << vec.size() << std::endl;

	// 	std::vector<int>::iterator bg;
	// 	std::vector<int>::iterator ed;
	// 	std::cout << "output" << std::endl;

	// 	bg = vec.begin();
	// 	ed = vec.end();
	// 	for (; bg != ed; bg++)
	// 	{
	// 		std::cout << "it: " << *bg << std::endl;
	// 	}
	// }
	// ft::vector<int> vec2;
	// vec2.push_back(25);
	// vec2.push_back(23);
	// vec2.push_back(24);
	// vec2.push_back(28);
	// vec2.push_back(20);

	// bg = vec2.begin();
	// ed = vec2.end();
	// try
	// {
	// 	vec.assign(ed, bg);
	// 	/* code */
	// }
	// catch ( const char *str)
	// {
	// 	std::cerr << str << '\n';
	// }

	// ft::vector<int>::iterator it;

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