#include <iostream>
#include <vector>
#include <iterator>
// template <typename T, class Alloc = std::allocator<T> >
// class itr
// {
// public :
// 	typedef Alloc allocator_type;
// 	// typedef typename T value_type;

// private :
// 	T *ptr;
// 	allocator_type _alloc;

// public:
// 	// typedef typename itr<value_type> itrr;

// 	struct iterator
// 	{
// 		T *ptr;
// 		T value;

// 		T &operator*() const
// 		{
// 			 return *m_ptr;
// 		}
// 	};
// 	itr<T> begin()
// 	{
// 		return ptr[0];
// 	}

// 	void add()
// 	{
// 		ptr = _alloc.allocate(5);
// 		for (size_t i = 0; i < 5; i++)
// 		{
// 			ptr[i] = i;
// 			std::cout << ptr[i] << " ";
// 		}
// 		std::cout << std::endl;
		
// 	}

// 	void print()
// 	{
// 		for (size_t i = 0; i < 5; i++)
// 		{
// 			std::cout << ptr[i] << " ";
// 		}
// 		std::cout << std::endl;
// 	}

// 	T &value(int pos)
// 	{
// 		return ptr[pos];
// 	}
	
// };

template <class iter>
void	test(iter f)
{
	typedef typename std::iterator_traits<iter>::value_type a;
	a nb = *f;
	std::cout << nb << std::endl;
}

int main()
{
	std::vector<int> v(5, 1337);
	int tab[] = {1337, 42, 19};
	test(tab);
	// itr<int> c;

	// itr<int>::itr 
	// // c.add();

	// // c.print() ;

	// std::cout << c.value(3) << std::endl;

	// std::vector<int> vec;

	// vec.push_back(5);
	// vec.push_back(10);
	// vec.push_back(3);
	// vec.push_back(2);

	// std::vector<int>::iterator it;
	// std::vector<int>::iterator ite;


	// it = vec.begin();
	// ite = vec.end();

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	it++;
	// }
}
