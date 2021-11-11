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
		// Member types
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef ft::MyIterator<value_type> iterator;
		typedef ft::MyIterator<const value_type> const_iterator;
		typedef ft::reverse_iterator<value_type> reverse_iterator;
		typedef ft::reverse_iterator<const value_type> const_reverse_iterator;

	private:
		allocator_type _alloc;
		value_type *_container;
		size_type _size;
		size_type _capacity;

	public:
		vector(const allocator_type &alloc = allocator_type()) : _container(nullptr), _size(0), _capacity(0), _alloc(alloc)
		{
		}

		vector(size_type __n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _size(__n), _capacity(__n), _alloc(alloc)
		{
			_container = _alloc.allocate(__n);
			for (unsigned long i = 0; i < __n; i++)
			{
				_container[i] = val;
			}
		}

		// void reallocate()
		// {
		// 	value_type *_new_container;
		// 	_capacity *= 2;
		// 	_new_container = _alloc.allocate(_capacity);
		// 	for (unsigned long i = 0; i < _capacity / 2; i++)
		// 	{
		// 		_new_container[i] = _container[i];
		// 		// _size++;
		// 	}
		// 	for (unsigned long i = _size; i < _capacity; i++)
		// 	{
		// 		_new_container[i] = 0;
		// 	}
		// 	delete[] _container;
		// 	_container = _new_container;
		// }

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type());

		// Iterators

		~vector(){};
		vector &operator=(const vector &rhs);
	};
}

#endif