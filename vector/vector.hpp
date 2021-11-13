#ifndef __CONTAINER_HPP
#define __CONTAINER_HPP

#include <iostream>
#include "enable_if.hpp"
#include "utils/utils.hpp"
#include "reverse_iterator.hpp"
#include "iterator.hpp"
#include "member_function.hpp"

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

		iterator begin()
		{
			// iterator ret();
			return iterator(&_container[0]);
		}

		const_iterator begin() const
		{
			return (iterator(&_container[0]));
		}

		iterator end()
		{
			return (iterator(&_container[_size]));
		}

		const_iterator end() const
		{
			return (iterator(&_container[_size]));
		}

		reverse_iterator rbegin()
		{
			return end();
		}

		const_reverse_iterator rbegin() const
		{
			return end();
		}

		reverse_iterator rend()
		{
			return (this->begin());
		}

		const_reverse_iterator rend() const
		{
			return (this->begin());
		}
		// NOTE Modifiers :

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_capacity);
		}

		void resize(size_type __n, value_type val = value_type())
		{
			T *new_container;

			if (__n >= _capacity)
			{

				_capacity *= 2;
				if (_capacity == 0)
					_capacity = 1;
				if (__n > _capacity)
					_capacity = __n;
			}
			if (_size > __n)
				_size = __n;
			new_container = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
			{
				new_container[i] = _container[i];
			}
			for (; _size < __n; _size++)
			{
				new_container[_size] = val;

			}
			delete[] _container;
			_container = new_container;
		}


		size_type capacity() const
		{
			return (_capacity);
		}

		bool empty() const
		{
			if (!_size)
				return (true);
		}

		void push_back(const value_type &val)
		{
			if (_size == _capacity)
			{
				resize(_capacity);
			}
			_container[_size] = val;
			_size++;
		}

		void reserve(size_type n)
		{
			T *new_container;
			if (n >= _capacity)
			{
				_capacity = n;
				new_container = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++)
				{
					new_container[i] = _container[i];
				}
			}
		}

		reference operator[](size_type n)
		{
			return ((_container[n]));
		}

		const_reference operator[](size_type n) const
		{
			return ((_container[n]));
		}

		reference at(size_type n)
		{
			puts(
				"without const");
			if (n < 0 || n > _size)
				throw std::out_of_range("index out of bounds");
			else
				return (_container[n]);
		}

		const_reference at(size_type n) const
		{
			puts(
				"with const");
			if (n < 0 || n > _size)
				throw std::out_of_range("index out of bounds");
			else
				return (_container[n]);
		}

		iterator insert(iterator position, const value_type &val)
		{
			*position = val;
		}

		reference front()
		{
			return (_container[0]);
		}

		const_reference front() const
		{
			return (_container[0]);
		}

		reference back()
		{
			return (_container[_size - 1]);
		}

		const_reference back() const
		{
			return (_container[_size - 1]);
		}

		template <class InputIterator>
		size_t iterlenght(InputIterator first, InputIterator last)
		{
			size_t lenght;
			bool excep;

			lenght = 0;
			excep = false;
			for (; first != last; first++)
			{
				if (std::string::npos == lenght)
					break;
				lenght++;
			}
			if (std::string::npos == lenght)
			{
				throw "vector";
			}
			return (lenght);
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			size_t __n;

			__n = iterlenght(first, last);
			if (__n > 0)
			{
				_size = 0;
				if (__n > _capacity)
					resize(__n);
				for (; first != last; first++)
				{
					_container[_size++] = *first;
				}
			}
		}

		void assign(size_type n, const value_type &val)
		{
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
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