#include <iostream>
#include "vector/vector.hpp"
#include "map/map.hpp"
#include <map>

// #include <vector>
// #include <utility>
// using namespace std

#include <iostream>
#include <map>

int main()
{
  ft::map<char, int> mymap;
  ft::map<char, int>::const_iterator itlow, itup;

  mymap['a'] = 20;
  mymap['b'] = 40;
  mymap['c'] = 60;
  mymap['d'] = 80;
  mymap['e'] = 100;

  itlow = mymap.begin(); // itlow points to b
  // itup = mymap.upper_bound ('d');   // itup points to e (not d!)

  std::cout << itlow->first << " " << itlow->second << std::endl;
  itlow++;
  std::cout << itlow->first << " " << itlow->second << std::endl;

  return 0;
}

// obeject const === finction