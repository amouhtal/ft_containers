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
  ft::map<char, int>::iterator it;

  // insert some values:
  mymap['a'] = 10;
  mymap['b'] = 20;
  mymap['c'] = 30;
  mymap['d'] = 40;
  mymap['e'] = 50;
  mymap['f'] = 60;

  mymap.erase('b');
  mymap.erase('c');
  // mymap.erase('d');

  // mymap.erase(it); // erasing by iterator

  // mymap.erase('c'); // erasing by key
  mymap.printf_map();
  // it = mymap.find('b');
  
  // mymap.erase(it, mymap.find('e')); // erasing by range
  // // show content:
  for (it = mymap.begin(); it != mymap.end(); it++)
    std::cout << it->first << " => " << it->second << '\n';
  return 0;
}