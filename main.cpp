#include <iostream>
#include "vector/vector.hpp"
#include "map/map.hpp"

// #include <vector>
// #include <utility>
// using namespace std;


int main()
{
	ft::map<int, int> ma;

	ft::map<int, int>::iterator it;


	ma.insert(ft::pair<int, int>(2, 6));
	ma.insert(ft::pair<int, int>(3, 6));
	it = ma.begin();
	++it;
	
	std::cout << it->first ;
	// ma[4] = 150;
	// ma[2] = 69;
	// ma[3] = 38;
	// ma[1] = 71;
	// it = ma.begin();

	// std::cout << it->second << "\n";

	
	// std::cout << it->first << "\n";

	// std::pair<int, int> nr;

	// nr.first = 10;
	// nr.second = 5;

	// root = t.insertNode(root, nr);

	return 0;
}