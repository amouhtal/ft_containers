#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP
#include <iostream>
#include "enable_if.hpp"
#include "utils/utils.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"

namespace ft
{
	// template <typename T>
	// class random_access_iterator : ft::iterator<ft::random_access_iterator_tag, T>
	// {
	// };
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};
	// enable_if<is_integral<type>>::type;

	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// typedef unsigned long size_type;
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef unsigned long size_type;
		typedef ft::MyIterator<value_type> iterator;

	private:
		allocator_type _alloc;
		value_type *_container;
		size_type _size;
		size_type _capacity;

	public:
		vector();
		vector(const allocator_type &alloc = allocator_type()) : _container(nullptr), _size(0), _capacity(0), _alloc(alloc)
		{
			;
		}
		vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(0), _capacity(n), _alloc(alloc)
		{
			_container = _alloc.allocate(n);
			for (unsigned long i = 0; i < n; i++)
			{
				_container[i] = val;
			}
			std::cout << _container[0];
		}

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

		// Iterators

		iterator begin()
		{
		}

		// const_iterator begin() const
		// {

		// }

		~vector(){};
		vector &operator=(const vector &rhs);
	};
}

#endif