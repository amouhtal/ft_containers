#include <iostream>
#include "vector/vector.hpp"
// #include "map/map.hpp"
#include <map>
// #include <vector>
// #include <utility>
// using namespace std

int main()
{

	std::map<int, int> ma;

	std::map<int, int>::iterator it;
	std::map<int, int>::iterator it_e;
	ma.insert(std::pair<int, int>(20, 6));
	ma.insert(std::pair<int, int>(15, 7));
	ma.insert(std::pair<int, int>(35, 8));
	ma.insert(std::pair<int, int>(30, 9));
	ma.insert(std::pair<int, int>(40, 10));
	ma.insert(std::pair<int, int>(25, 11));

	it = ma.begin();
	it++;
	it++;
	ma.insert(it,std::pair<int, int>(13, 11));
	it = ma.begin();
	it_e = ma.end();
	for(; it != it_e ; it++)
		std::cout << " key :" << it->first << "\n";
	// it = ma.begin();

	return 0;
}