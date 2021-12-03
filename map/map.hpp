#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include "../vector/utils/utils.hpp"

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
		typedef iterator_type Iterator;
		typedef iterator_category iterator_traits<Iterator>::iterator_category;
		typedef value_type iterator_traits<Iterator>::value_type;
		typedef difference_type iterator_traits<Iterator>::difference_type;
		typedef pointer iterator_traits<Iterator>::pointer;
		typedef reference iterator_traits<Iterator>::reference
	};

	template <class Iterator>
	class iterator
	{
    		Iterator _it;
		public :
			typedef iterator_type Iterator;
			typedef iterator_category iterator_traits<Iterator>::iterator_category;
			typedef value_type iterator_traits<Iterator>::value_type;
			typedef difference_type iterator_traits<Iterator>::difference_type;
			typedef pointer iterator_traits<Iterator>::pointer;
			typedef reference iterator_traits<Iterator>::reference;
		
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::allocator < ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef value_compare;
		typedef allocator_type;
		typedef allocator_type::reference reference;
		typedef allocator_type::const_reference const_reference;
		typedef allocator_type::pointer pointer;
		typedef allocator_type::const_pointer const_pointer;
		typedef iterator;
		typedef reverse_iterator<iterator> const_iterator;
		typedef reverse_iterator<const_iterator> reverse_iterator;
		typedef const_reverse_iterator const_reverse_iterator;
		typedef iterator_traits<iterator>::difference_type difference_type;
		typedef size_t size_type;
	};
}

#endif