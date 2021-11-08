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
		T *p;

	public:
		MyIterator(int *x) : p(x) {}
		MyIterator(const MyIterator &mit) : p(mit.p) {}

		T *base() const
		{
			return (p);
		}

		T &operator*()
		{
			return *p;
		}

		MyIterator &operator++()
		{
			++p;
			return *this;
		}

		MyIterator operator+(ptrdiff_t __n)
		{
			p + __n;
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
			p + __n;
			return (*this);
		}

		MyIterator &operator-(ptrdiff_t __n)
		{
			return (p - __n);
		}

		MyIterator operator--()
		{
			p++;
			return p;
		}

		MyIterator operator--(int)
		{
			MyIterator tmp(*this);
			operator--();
			return tmp;
		}

		MyIterator operator-=(ptrdiff_t __n)
		{
			p - __n;
			return (*this);
		}

		// MyIterator operator-(ptrdiff_t __n)
		// {
		// 	p - __n;
		// 	return (*this);
		// }

		T operator[](ptrdiff_t __n)
		{
			return (p[__n]);
		}

		bool operator==(const MyIterator &rhs) const
		{
			return p == rhs.p;
		}

		bool operator!=(const MyIterator &rhs) const
		{
			return p != rhs.p;
		}
	};
}
#endif