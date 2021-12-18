#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include "../vector/utils/utils.hpp"
#include "avl.hpp"

namespace ft
{

	template <class Iterator>
	class map_reverse_iterator
	{
		typedef Iterator iterator_type;
		typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
		typedef typename iterator_traits<Iterator>::value_type value_type;
		typedef typename iterator_traits<Iterator>::difference_type difference_type;
		typedef typename iterator_traits<Iterator>::pointer pointer;
		typedef typename iterator_traits<Iterator>::reference reference;
	};

	template <class pair, typename NodPtr>
	class MapIterator 
	{
	public:

	private:
		NodPtr _tree;

	public:
		MapIterator() : _tree(nullptr) {}
		template <class T1>
			MapIterator(const MapIterator<T1, NodPtr> &it) : _tree(it.base()) {}
		explicit MapIterator(NodPtr node) : _tree(node) {}
		NodPtr base() const
		{
			return this->_tree;
		}

		pair &operator*() const
		{
			return (_tree)->pair;
		}

		pair *operator->()
		{
			return &(_tree->pair);
		}

		pair &get_pair()
		{
			return (_tree->pair);
		}

		// iterator &operator=(iterator const &rhs)
		// {
		// 	this->_tree = rhs._tree;
		// 	return (*this);
		// }

		// Node &operator=(Node const &rhs)
		// {
		// 	this->_tree = rhs;
		// 	return (*this);
		// }

		MapIterator &operator++()
		{
			_tree = get_next(_tree);
			return (*this);
		}

		MapIterator operator++(int)
		{
			MapIterator temp = *this;
			_tree = get_next(_tree);

			return temp;
		}

		MapIterator &operator--()
		{
			_tree = get_precedent<pair>(_tree);
			return (*this);
		}

		MapIterator operator--(int)
		{
			MapIterator temp = *this;
			_tree = get_precedent<pair>(_tree);

			return temp;
		}

		bool operator!()
		{
			if (_tree == nullptr)
				return true;
			return false;
		}

		bool operator==(MapIterator const &rhs)
		{
			if (_tree == rhs._tree)
				return true;
			return false;
		}

		bool operator!=(MapIterator const &rhs)
		{
			if (_tree != rhs._tree)
				return true;
			return false;
		}

		bool empty() const
		{
			if (_tree)
				return true;
			return false;
		}
	};

	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;

		typedef ft::pair<const key_type, mapped_type> value_type;
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
			bool operator()(const key_type &a, const key_type &b) const
			{
				return (_comp(a, b));
			}
		};

		typedef Node<value_type> Node;
		typedef Node *NodePtr;

		typedef MapIterator<value_type, NodePtr> iterator;
		typedef MapIterator<const value_type, NodePtr> const_iterator;
		// typedef MapIterator<const_value_type, MapKeyCompare> const_iterator;

		typedef Avl<value_type, MapKeyCompare> Avl_algo;
		// typedef typename Avl<value_type, MapKeyCompare>::mynode Node;

	private:
		MapKeyCompare m_comp;
		allocator_type m_allocator;
		Avl_algo _avl;
		Node *_tree;
		Node *end_tree;

	public:
		explicit map(const key_compare &comp = key_compare(),
					 const allocator_type &alloc = allocator_type()) : m_comp(comp), m_allocator(alloc), _tree(nullptr)
		{
			end_tree = new Node();
		}

		// iterator begin()
		// {
		// 	iterator it(_avl.most_left(_tree));
		// 	return (it);
		// }

		const_iterator begin() const
		{
			const_iterator it(_avl.most_left(_tree));

			return (it);
		}

		iterator end()
		{
			iterator it(end_tree);
			return (it);
		}

		const_iterator end() const
		{
			const_iterator it(_avl.most_right(end_tree));
			return (it);
		}

		size_type count(const key_type &k) const
		{
			return _avl.count(_tree, make_pair(k, mapped_type()));
		}

		bool empty() const
		{
			if (_tree)
				return false;
			return true;
		}

		iterator find(const key_type &k)
		{
			bool exist;
			Node *ret = (_avl.search_by_key(make_pair(k, mapped_type()), exist, _tree));

			if (exist)
				return iterator(ret);

			return end();
		}

		const_iterator find(const key_type &k) const
		{
			const_iterator it(_tree);

			if (k < it._tree->pair.first)
			{
				it = it._tree->left;
				it = find(it._tree->left->pair.first);
			}
			else if (k > it._tree->pair.first)
			{
				it = it._tree->right;
				it = find(it._tree->right->pair.first);
			}
			else
			{
				return it;
			}

			return it;
		}

		pair<iterator, bool> insert(const value_type &val)
		{
			bool bl = false;
			iterator ret(_avl.search_by_key(val, bl, _tree));
			if (bl == true)
			{
				return ft::make_pair(ret, false);
			}
			_tree = _avl.insertNode(_tree, val);
			_tree->parent = end_tree;
			end_tree->left = _tree;

			return ft::make_pair(iterator(_avl.search_by_key(val, bl, _tree)), true);
		}

		iterator insert(iterator position, const value_type &val)
		{

			insert(val);
			iterator map_it = begin();
			while (map_it++)
			{
				if (map_it._tree->pair.first == val.first)
					break;
			}
			return map_it;
		}

		void printf_map()
		{
			_avl.printTree(_tree, "", true);
		}

		void erase(iterator position)
		{
			_tree = _avl.deleteNode(_tree, position.get_pair());
		}

		size_type erase(const key_type &k)
		{
			value_type val(k, 5);
			bool b = true;
			Node *pos = _avl.search_by_key(val, b, _tree);
			_avl.deleteNode(_tree, pos->pair);
			return 5;
		}

		void swap(map &x)
		{
			MapKeyCompare tmp_m_comp;
			allocator_type tmp_m_allocator;
			Avl_algo tmp_avl;
			Node *tmp_tree;
			Node *tmp_end;

			tmp_m_comp = x.m_comp;
			tmp_m_allocator = x.m_allocator;
			tmp_avl = x._avl;
			tmp_tree = x._tree;
			tmp_end = x.end_tree;

			x.m_comp = this->m_comp;
			x.m_allocator = this->m_allocator;
			x._avl = this->_avl;
			x._tree = this->_tree;
			x.end_tree = this->end_tree;

			this->m_comp = tmp_m_comp;
			this->m_allocator = tmp_m_allocator;
			this->_avl = tmp_avl;
			this->_tree = tmp_tree;
			this->end_tree = tmp_end;
		}

		mapped_type &operator[](const key_type &k)
		{
			return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		void clear()
		{
			_tree = _avl.clear2(_tree);
		}

		size_type size()
		{
			return (_avl.size2(_tree));
		}

		size_type max_size() const
		{
			return m_allocator.max_size();
		}

		iterator lower_bound(const key_type &k)
		{
			iterator it(_avl.most_left(_tree));
			while (m_comp(it->first, k) && it != end())
			{
				it++;
			}
			return it;
		}

		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator it(_avl.most_left(_tree));
			while (m_comp(it->first, k) && it != end())
			{
				it++;
			}
			return it;
		}

		iterator upper_bound(const key_type &k)
		{
			iterator it(_avl.most_left(_tree));
			while (m_comp(it->first, k) && it != end())
			{
				it++;
			}
			if (it->first == k)
				it++;
			return it;
		}

		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator it(_avl.most_left(_tree));
			while (m_comp(it->first, k) && it != end())
				it++;
			if (it->first == k)
				it++;
			return it;
		}

		pair<iterator, iterator> equal_range(const key_type &k)
		{
			pair<iterator, iterator> ret;

			ret.first = lower_bound(k);
			ret.second = upper_bound(k);
			return ret;
		}

		allocator_type get_allocator() const
		{
			return allocator_type();
		}

		// template <class InputIterator>
		// void insert(InputIterator first, InputIterator last)
		// {

		// }
	};
}

#endif

/*

candidate function not viable: no known conversion from
'MapIterator<pair<ft::map<char, int, std::__1::less<char>, std::__1::allocator<ft::pair<const char, int> > >::key_type, ft::map<char, int, std::__1::less<char>, std::__1::allocator<ft::pair<const char,
	  int> > >::mapped_type>, [...]>
	' to 'const MapIterator<pair<const char, const int>, [...]>' for 1st argument
				iterator &operator=(iterator const &rhs)

*/