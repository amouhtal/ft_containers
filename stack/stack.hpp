#ifndef __STACK_HPP
#define __STACK_HPP
#include <deque>

namespace ft
{
	template <class T, class Container = std::deque<T> >
	class stack
	{
	private:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;
		container_type content;

	public:
		explicit stack(const container_type &ctnr = container_type())
		{
			content = ctnr;
		}

		bool empty() const
		{
			return content.empty();
		}

		size_type size() const
		{
			return (content.size());
		}

		void push(const value_type &val)
		{
			content.push_back(val);
		}

		value_type &top()
		{
			return (*(--content.end()));
		}

		const value_type &top() const
		{
			return (*(--content.end()));
		}

		void pop()
		{
			return ((content.pop_back()));
		}

		template <class T, class Container>
		bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}

		template <class T, class Container>
		bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}

		template <class T, class Container>
		bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}

		template <class T, class Container>
		bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}

		template <class T, class Container>
		bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}

		template <class T, class Container>
		bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
		{

		}
	};
}

#endif