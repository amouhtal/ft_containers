#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

# include "vector.hpp"
# include "iterators_traits.hpp"
namespace ft
{

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
		reverse_iterator() : it(nullptr)
		{
		}

		explicit reverse_iterator(iterator_type it)
		{
			this->it = it;
		}

		iterator_type base() const
		{
			return (it);
		}

		reference operator*() const
		{
			return (it);
		}

		reverse_iterator operator+(difference_type n) const
		{
			return (it - n);
		}

		reverse_iterator &operator++()
		{
			it--;
			return it;
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
			return it;
		}

		reverse_iterator operator-(difference_type __n) const
		{
			it + __n;
			return *this;
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
			return it;
		}

		// reference operator[](difference_type n) const
		// {
		// 	return ;
		// }

	private:
		iterator_type it;
	};
}

#endif