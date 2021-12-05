#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include "../vector/utils/utils.hpp"
#include "avl.hpp"

namespace ft
{

	// template <class Iterator>
	// class map_reverse_iterator
	// {
	// 	typedef  Iterator iterator_type;
	// 	typedef  typename iterator_traits<Iterator>::iterator_category iterator_category;
	// 	typedef  typename iterator_traits<Iterator>::value_type value_type;
	// 	typedef  typename iterator_traits<Iterator>::difference_type difference_type;
	// 	typedef  typename iterator_traits<Iterator>::pointer pointer;
	// 	typedef  typename iterator_traits<Iterator>::reference reference;
	// };

	template <class pair>
	class MapIterator
	{
	public:
		typedef Node<pair> tree;

	private:
		Node<pair> *_node;

	public:
		MapIterator() : _node(nullptr) {}
		MapIterator(tree const &node) : _node(node) {}
		MapIterator(MapIterator<pair> &MapIterator) : _node(MapIterator._node) {}

		pair &operator->()
		{
			return (_node->pair);
		}

		MapIterator &operator=(MapIterator const &rhs)
		{
			this->_node = rhs._node;
			return (*this);
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::allocator<ft::pair<const Key, T> > value_type;
		typedef Compare key_compare;
		// typedef typename value_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef MapIterator<value_type> iterator;
		// typedef map_reverse_iterator<iterator> const_iterator;
		// typedef map_reverse_iterator<const_iterator> map_reverse_iterator;
		// typedef const_reverse_iterator const_reverse_iterator;
		typedef typename iterator_traits<pointer>::difference_type difference_type;
		typedef size_t size_type;
		typedef Avl<value_type, Compare> Avl_algo;

	private:
		Node< pair > *_node;
		Avl_algo _avl;

	public:
		pair<iterator, bool> insert(const value_type &val)
		{
			_node = _avl.insert(value_type);
		}
	};
}

#endif