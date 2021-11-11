#ifndef __MEMBER_FUNCTION_HPP__
#define __MEMBER_FUNCTION_HPP__

namespace ft
{
	iterator begin()
	{
		iterator t(&_container[0]);
		return t;
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

	void resize(size_type n, value_type val = value_type())
	{
		T *new_container;

		if (_capacity < n)
		{
			_capacity *= 2;
			if (_capacity < n)
				_capacity = n;
		}
		if (_size > n)
		{
			_size = n;
		}
		new_container = _alloc.allocate(_capacity);
		for (size_t i = 0; i < _size; i++)
		{
			new_container[i] = _container[i];
		}
		for (size_t i = _size; i < _capacity; i++)
		{
			new_container[i] = val;
		}
		delete[] _container;
		_container = new_container;
	}

	void push_back(const value_type &val)
	{
		_container[_size] = val;
		_size++;
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

	void reserve(size_type n)
	{
		if (n > _capacity)
		{
			if (_capacity < n)
			{
				_capacity *= 2;
				if (_capacity < n)
					_capacity = n;
			}
			new_container = _alloc.allocate(n);
			for (size_t i = 0; i < _size; i++)
			{
				new_container[i] = _container[i];
			}
		}
	}

	iterator insert(iterator position, const value_type &val)
	{
		*position = val;
	}

	void insert(iterator position, size_type n, const value_type &val)
	{
	}

	template <class InputIterator>
	void insert(iterator position, InputIterator first, InputIterator last)
	{
	}
}

#endif