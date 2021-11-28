#ifndef __UTILS_HPP__
#define __UTILS_HPP__

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
								 InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
								 Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}

	/*template <class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		first_type first;
		second_type second;

		pair() : first(), second(){};

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second){};

		pair(const first_type &a, const second_type &b) : first(a), second(b){};

		pair &operator=(const pair &rhs)
		{
			if (this == &rhs)
				return *this;
			this->second = rhs.second;
			this->second = rhs.second;
			return *this;
		}

		// void swap(pair &pr) noexcept(noexcept(swap(first, pr.first)) &&
		// 							 noexcept(swap(second, pr.second)))
		// {
		// 	swap(first, pr.first);
		// 	swap(second, pr.second);
		// }
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	}*/

}
#endif