#ifndef MY_ITERATOR_HPP
#define MY_ITERATOR_HPP

#include "vector.hpp"

namespace ft
{
	// struct random_access_iterator_tag {};

	template <typename T>
	class MyIterator : public std::iterator<std::random_access_iterator_tag, T>
	{
	private:
		T *ptr;

	public:
		MyIterator():ptr(nullptr){}
		MyIterator(T *x) : ptr(x) {}
		MyIterator(const MyIterator &mit) : ptr(mit.ptr) {}

		T *base() const
		{
			return (ptr);
		}

		T &operator*()
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
			return (ptr - __n);
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

		// MyIterator operator-(ptrdiff_t __n)
		// {
		// 	ptr - __n;
		// 	return (*this);
		// }

		T operator[](ptrdiff_t __n)
		{
			return (ptr[__n]);
		}

		bool operator==(const MyIterator &rhs) const
		{
			return ptr == rhs.p;
		}

		bool operator!=(const MyIterator &rhs) const
		{
			return ptr != rhs.ptr;
		}
	};
}
#endif