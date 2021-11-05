#include <iostream>

template <typename T>
struct has_typedef_foobar
{
	// Types "yes" and "no" are guaranteed to have different sizes,
	// specifically sizeof(yes) == 1 and sizeof(no) == 2.
	typedef char yes[1];
	typedef char no[2];

	template <typename C>
		static yes &test(typename C::foobar *);

	template <typename>
		static no &test(...);

	// If the "sizeof" of the result of calling test<T>(nullptr) is equal to
	// sizeof(yes), the first overload worked and T has a nested type named
	// foobar.
	static const bool value = sizeof(test<T>(nullptr)) == sizeof(yes);
};

struct foo
{
	typedef float foobar;
};

int main()
{
	std::cout << std::boolalpha;
	std::cout << has_typedef_foobar<int>::value << std::endl; // Prints false
	std::cout << has_typedef_foobar<foo>::value << std::endl; // Prints true
}