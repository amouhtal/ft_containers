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
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	struct iterator
	{
		typedef T value_type;
		typedef Distance difference_type;
		typedef Pointer pointer;
		typedef Reference reference;
		typedef Category iterator_category;
	};

	template <class Iterator>
	struct iterator_traits
	{
		typedef typename Iterator::difference_type difference_type;
		typedef typename Iterator::value_type value_type;
		typedef typename Iterator::pointer pointer;
		typedef typename Iterator::reference reference;
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T *>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T *>
	{
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef typename std::random_access_iterator_tag iterator_category;
	};

	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
		typedef Iterator iterator_type;

	private:
		iterator_type it;

	public:
		reverse_iterator() : it(nullptr)
		{
		}

		explicit reverse_iterator(iterator_type it)
		{
			this->it = it;
		}

		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter> &rev_it) : it(rev_it.base()){};

		iterator_type base() const
		{
			return (it);
		}

		reference operator*() const
		{
			iterator_type _tmp = it;
			return *--_tmp;
		}

		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(base() - n);
		}

		reverse_iterator &operator++()
		{
			it--;
			return *this;
		}

		reverse_iterator operator++(int)
		{
			reverse_iterator temp = *this;
			++(*this);
			return temp;
		}

		reverse_iterator &operator+=(difference_type __n)
		{
			it -= __n;
			return *this;
		}

		reverse_iterator operator-(difference_type __n) const
		{
			return reverse_iterator(base() + __n);
		}

		reverse_iterator &operator--()
		{
			++it;
			return (*this);
		}

		reverse_iterator operator--(int)
		{
			reverse_iterator temp = *this;
			--(*this);
			return temp;
		}

		reverse_iterator &operator-=(difference_type __n)
		{
			it += __n;
			return *this;
		}

		bool operator!=(const reverse_iterator &rhs)
		{
			return (this->it != rhs.it);
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}
	};

	template <typename T>
	class MyIterator : public ft::iterator<std::random_access_iterator_tag, typename iterator_traits<T>::value_type>
	{
	public:
		typedef T pointer;
		typedef typename iterator_traits<pointer>::iterator_category iterator_category;
		typedef typename iterator_traits<pointer>::value_type value_type;
		typedef typename iterator_traits<pointer>::difference_type difference_type;
		typedef typename iterator_traits<pointer>::reference reference;

	private:
		pointer ptr;

	public:
		MyIterator() : ptr(nullptr) {}
		MyIterator(pointer it) : ptr(it) {}
		template <typename Iter>
		MyIterator(const MyIterator<Iter> &mit) : ptr(mit.base()) {}

		pointer base() const
		{
			return (ptr);
		}

		reference operator*()
		{
			return *ptr;
		}

		MyIterator &operator++()
		{
			++ptr;
			return *this;
		}

		MyIterator operator+(ptrdiff_t __n)
		{
			ptr += __n;
			return (*this);
		}

		MyIterator operator++(int)
		{
			MyIterator tmp(*this);
			operator++();
			return tmp;
		}

		MyIterator operator+=(ptrdiff_t __n)
		{
			ptr += __n;
			return (*this);
		}

		MyIterator &operator-(ptrdiff_t __n)
		{
			ptr -= __n;
			return (*this);
		}

		MyIterator operator--()
		{
			ptr--;
			return ptr;
		}

		MyIterator operator--(int)
		{
			MyIterator tmp(*this);
			operator--();
			return tmp;
		}

		MyIterator operator-=(ptrdiff_t __n)
		{
			ptr -= __n;
			return (*this);
		}

		reference operator[](ptrdiff_t __n)
		{
			return (ptr[__n]);
		}

		bool operator==(const MyIterator &rhs) const
		{
			return ptr == rhs.ptr;
		}

		bool operator!=(const MyIterator &rhs) const
		{
			return (this->ptr != rhs.ptr);
		}

		bool operator<(const MyIterator &rhs) const
		{
			return (this->ptr < rhs.ptr);
		}
	};

	template <typename T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef size_t size_type;
		typedef ft::MyIterator<pointer> iterator;
		typedef ft::MyIterator<const_pointer> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

	private:
		allocator_type _alloc;
		value_type *_container;
		size_type _size;
		size_type _capacity;

	public:
		vector(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _container(nullptr), _size(0), _capacity(0)
		{
		}

		vector(size_type __n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : _alloc(alloc), _container(nullptr), _size(__n), _capacity(__n)
		{
			_container = _alloc.allocate(__n);
			for (unsigned long i = 0; i < __n; i++)
			{
				_container[i] = val;
			}
		}

		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			   typename enable_if<!is_integral<InputIterator>::value>::type * = nullptr) : _alloc(alloc)
		{
			_size = iterlenght(first, last);
			_capacity = _size;

			_container = _alloc.allocate(_capacity);
			pointer bg;
			bg = _container;
			int i = 0;
			for (InputIterator it = first; it != last; it++)
			{
				_container[i++] = *it;
			}
		}

		vector(const vector &other)
		{
			*this = other;
		}

		const_iterator begin() const
		{
			return const_iterator(_container);
		}

		iterator begin()
		{
			return iterator(&_container[0]);
		}

		iterator end()
		{
			return (iterator(&_container[_size]));
		}

		const_iterator end() const
		{
			return (const_iterator(&_container[_size]));
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(this->begin());
		}

		size_type size() const
		{
			return (_size);
		}

		size_type max_size() const
		{
			return (_alloc.max_size());
		}

		void resize(size_type __n, value_type val = value_type())
		{
			pointer new_container;
			size_type old_cap = _capacity;
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
				new_container[i] = _container[i];
			for (; _size < __n; _size++)
				new_container[_size] = val;
			for (size_t i = 0; i < _size; i++)
			{
				_alloc.destroy(_container + i);
			}
			_alloc.deallocate(_container, old_cap);
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
			return false;
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

		void pop_back()
		{
			_alloc.destroy(&_container[_size - 1]);
			_size -= 1;
		}

		void reserve(size_type n)
		{
			T *new_container;
			size_type old_cap = _capacity;

			if (n > _capacity)
			{
				_capacity = n;
				new_container = _alloc.allocate(_capacity);
				for (size_t i = 0; i < _size; i++)
				{
					new_container[i] = _container[i];
				}
				_alloc.deallocate(_container, old_cap);
				_container = new_container;
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
			if (n < 0 || n > _size)
				throw std::out_of_range("index out of bounds");
			else
				return (_container[n]);
		}

		const_reference at(size_type n) const
		{
			if (n < 0 || n > _size)
				throw std::out_of_range("index out of bounds");
			else
				return (_container[n]);
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

			lenght = 0;
			for (; first != last; first++)
			{
				lenght++;
			}
			return (lenght);
		}

		template <class InputIterator>

		void assign(InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type * = nullptr)
		{
			size_t __n;

			__n = iterlenght(first, last);
			if (__n > 0)
			{
				if (__n > _capacity)
					resize(__n);
				_size = 0;
				for (; first != last; first++)
				{
					_container[_size++] = *first;
				}
			}
		}

		void assign(size_type __n, const value_type &val)
		{
			if (__n > 0)
			{
				if (__n > _capacity)
				{
					resize(__n);
				}
				_size = 0;
				for (size_type i = 0; i < __n; i++)
				{
					_container[_size++] = val;
				}
			}
		}

		iterator insert(iterator position, const value_type &val)
		{
			value_type temp;
			value_type temp2;
			iterator it;
			iterator ite;

			size_t i = 0;

			if (position.base())
				temp = *position;
			it = this->begin();

			while (it != position)
			{
				i++;
				it++;
			}

			if (_size == _capacity)
			{
				resize(_capacity);
			}

			it = iterator(_container + i);

			_size++;
			_container[i++] = val;
			while (i < _size)
			{
				temp2 = _container[i];
				_container[i++] = temp;

				temp = _container[i];
				_container[i++] = temp2;
			}
			return (it);
		}

		void insert(iterator position, size_type n, const value_type &val)
		{
			size_type i;

			i = 0;

			while (i < n)
			{
				position = insert(position, val);
				position++;
				i++;
			}
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value>::type * = nullptr)
		{
			T val;
			while (first != last)
			{
				val = *first;
				position = insert(position, val);
				position++;
				first++;
			}
		}

		iterator erase(iterator position)
		{
			size_t i;

			i = 0;
			iterator it;
			T temp;
			it = this->begin();

			while (it != position)
			{
				it++;
				i++;
			}
			while (i < _size - 1)
			{
				temp = _container[i + 1];
				_container[i] = temp;
				i++;
			}
			_alloc.destroy(&_container[_size]);
			_size--;
			return (it);
		}

		iterator erase(iterator first, iterator last)
		{
			iterator it;
			int i = 0;
			int n = 0;

			it = first;
			while (it != last)
			{
				n++;
				it++;
			}

			while (i != n)
			{
				erase(first);
				i++;
			}
			return it;
		}

		void swap(vector &x)
		{
			allocator_type temp_alloc;
			value_type *temp_container;
			size_type temp_size;
			size_type temp_capacity;

			temp_alloc = _alloc;
			temp_container = _container;
			temp_size = _size;
			temp_capacity = _capacity;

			_alloc = x._alloc;
			_container = x._container;
			_size = x._size;
			_capacity = x._capacity;

			x._alloc = temp_alloc;
			x._container = temp_container;
			x._size = temp_size;
			x._capacity = _capacity;
		}

		void clear()
		{
			size_t i;

			i = 0;

			while (i < _size)
			{

				_alloc.destroy(&_container[i]);
				i++;
			}
			_size = 0;
		}

		allocator_type get_allocator() const
		{
			return allocator_type();
		}

		~vector(){};

		vector &operator=(const vector &rhs)
		{
			_alloc = rhs._alloc;
			_size = rhs._size;
			_capacity = rhs._capacity;
			_container = _alloc.allocate(_capacity);
			for (size_t i = 0; i < _size; i++)
			{
				_container[i] = rhs._container[i];
			}
			return (*this);
		}
	};
	
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs,
					const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs,
					const vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs,
				   const vector<T, Alloc> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs,
					const vector<T, Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs,
				   const vector<T, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs,
					const vector<T, Alloc> &rhs)
	{
		return (!(lhs <= rhs));
	}
}

#endif