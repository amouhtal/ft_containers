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

	template <class pair, typename comp>
	class MapIterator
	{
	public:
		typedef Avl<pair, comp> Avl;
		typedef MapIterator<pair, comp> iterator;
		typedef Node<pair> Node;

	private:
		Node *_tree;

	public:
		MapIterator() : _tree() {}
		MapIterator(Node *node) : _tree(node) {}
		MapIterator(iterator &MapIterator) : _tree(MapIterator._tree) {}

		pair *operator->()
		{
			return &(_tree->pair);
		}

		iterator &operator=(iterator const &rhs)
		{
			this->_tree = rhs._tree;
			return (*this);
		}

		iterator &operator++()
		{
			_tree = get_next<pair>(_tree);
			return (*this);
		}

		iterator operator++(int)
		{
			iterator temp = *this;
			_tree = get_next<pair>(_tree);

			return temp;
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;

		typedef ft::pair<key_type, mapped_type> value_type;
		typedef ft::pair<const key_type, const mapped_type> const_value_type;

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
		typedef MapIterator<const_pointer, MapKeyCompare> const_iterator;

		typedef Avl<value_type, MapKeyCompare> Avl_algo;
		typedef typename Avl<value_type, MapKeyCompare>::mynode Node;

	private:
		MapKeyCompare m_comp;
		allocator_type m_allocator;
		Avl_algo _avl;
		Node *_tree;

	public:
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : m_comp(comp), m_allocator(alloc), _tree(nullptr)
		{
		}

		iterator begin()
		{
			iterator it(_avl.most_left(_tree));
			return (it);
		}

		iterator end()
		{
			Node it(_avl.most_right(_tree));
			return (it);
		}

		pair<iterator, bool> insert(const value_type &val)
		{
			bool bl = false;

			pair<iterator, bool> p;

			iterator ret(_avl.search_by_key(val, bl, _tree));
			Node *tmp = _avl.newNode(val);
			iterator ret1(tmp);

			if (bl == true)
			{
				p.first = ret;
				p.second = false;
				return p;
			}
			else
			{
				p.second = true;
				p.first = ret1;
			}
			_tree = _avl.insertNode(_tree, val);
			return (p);
		}
		// const_iterator end() const
		// {
		// 	const_iterator it(_avl.most_right());
		// 	return (it);
		// }

		// const_iterator begin() const
		// {
		// 	const_iterator it(_avl.most_left());

		// 	return (it);
		// }

		iterator insert(iterator position, const value_type &val)
		{
			iterator map_it(_tree);

			if (map_it->first > position->first)
			{
				map_it = map_it++;
			}
		}

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last)
		// {

		// }
	};
}

#endif