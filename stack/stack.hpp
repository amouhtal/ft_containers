#ifndef __STACK_HPP
#define __STACK_HPP
#include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	protected:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
		container_type c;

	public:

		stack &operator =(const stack &other)
		{
			c = other.c;
		}

		explicit stack(const container_type &ctnr = container_type())
		{
			c = ctnr;
		}

		bool empty() const
		{
			return c.empty();
		}

		size_type size() const
		{
			return (c.size());
		}

		void push(const value_type &val)
		{
			c.push_back(val);
		}

		value_type &top()
		{
			return (*(--c.end()));
		}

		const value_type &top() const
		{
			return (*(--c.end()));
		}

		void pop()
		{
			return ((c.pop_back()));
		}

	};

	template <class _T, class C>
	bool operator==(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs == rhs);
	}

	template <class _T, class C>
	bool operator!=(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs != rhs);
	}

	template <class _T, class C>
	bool operator<(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs < rhs);
	}

	template <class _T, class C>
	bool operator<=(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs <= rhs);
	}
	template <class _T, class C>
	bool operator>(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs > rhs);
	}
	template <class _T, class C>
	bool operator>=(const stack<_T, C> &lhs, const stack<_T, C> &rhs)
	{
		return (lhs >= rhs);
	}
}

#endif