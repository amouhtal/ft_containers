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

	template <class pair , typename comp>
	class MapIterator
	{
	public:
		typedef Avl<pair, comp> tree;
		typedef MapIterator<pair, comp> iterator;

	private:
		tree	_node;

	public:
		MapIterator() {}
		MapIterator(tree const &node) : _node(node) {}
		MapIterator(iterator &MapIterator) : _node(MapIterator._node) {}

		pair *operator->() 
		{
			return &(_node.get_data());
		}

		iterator &operator=(iterator const &rhs)
		{
			this->_node = rhs._node;
			return (*this);
		}
		iterator &operator++()
		{
			++_node;
			return (*this);
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;

		typedef ft::pair<key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		// typedef map_reverse_iterator<iterator> const_iterator;
		// typedef map_reverse_iterator<const_iterator> map_reverse_iterator;
		// typedef const_reverse_iterator const_reverse_iterator;
		typedef typename iterator_traits<pointer>::difference_type difference_type;
		typedef size_t size_type;

		class MapKeyCompare : public std::binary_function<ft::pair<key_type, mapped_type>, value_type, bool>
		{
			friend class map;

		protected:
		// typedef Compare value_compare;
			key_compare _comp;
			explicit MapKeyCompare(key_compare comp) : _comp(comp) {}
		public:
			MapKeyCompare(){};
			virtual ~MapKeyCompare() {}

			bool operator()(const value_type &a, const value_type &b) const
			{
				return (_comp(a.first, b.first));
			}
			bool operator()(const value_type &a, const key_type &b) const
			{
				return (_comp(a.first, b));
			}
			bool operator()(const key_type &a, const value_type &b) const
			{
				return (_comp(a, b.first));
			}
		};

		typedef MapIterator<value_type, MapKeyCompare> iterator;
		typedef Avl<value_type, MapKeyCompare> Avl_algo;

	private:
		MapKeyCompare m_comp;
		allocator_type m_allocator;
		Avl_algo _avl;

	public:
		// explicit map(const key_compare &comp = key_compare(),
		// 			 const allocator_type &alloc = allocator_type())
		// 	: m_comp(comp), m_allocator(alloc),
		// 	  _avl(nullptr)
		// {
		// }

		explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type())
			{
				// Avl_algo tmp(key_compare);

				// _avl = tmp;
			}
		pair<iterator, bool> insert(const value_type &val)
		{
			_avl.insert(val);
			pair<iterator,bool> p;
			return (p);
		}

		iterator begin()
		{
			iterator it(_avl);

			return(it);
		}
		// iterator insert(iterator position, const value_type &val)
		// {

		// }

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last)
		// {

		// }
	};
}

#endif