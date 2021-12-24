#ifndef __MAP_HPP__
#define __MAP_HPP__

#include <iostream>
#include "../vector/vector.hpp"
#include "../vector/utils/utils.hpp"
#include "avl.hpp"

namespace ft
{

	// template <class Iterator>
	// class map_reverse_iterator
	// {
	// 	typedef Iterator iterator_type;
	// 	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	// 	typedef typename iterator_traits<Iterator>::value_type value_type;
	// 	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	// 	typedef typename iterator_traits<Iterator>::pointer pointer;
	// 	typedef typename iterator_traits<Iterator>::reference reference;
	// };

	template <typename iterator>
	class map_reverse_iterator
	{
	public:
		iterator _tree;

	public:
		map_reverse_iterator() : _tree(nullptr) {}
		template <class T1>
		map_reverse_iterator(const map_reverse_iterator<iterator> &it) : _tree(it.base()) {}
		explicit map_reverse_iterator(iterator node) : _tree(node) {}
		typedef typename iterator::value_type pair;

		iterator base() const
		{
			return _tree;
		}

		pair &operator*() const
		{
			return (*--base());
		}

		pair *operator->()
		{
			return &(operator*());
		}

		pair &get_pair()
		{
			return (_tree.get_pair());
		}

		map_reverse_iterator &operator++()
		{
			--_tree;
			return (*this);
		}

		map_reverse_iterator operator++(int)
		{
			map_reverse_iterator temp = *this;
			_tree--;
			return temp;
		}

		map_reverse_iterator &operator--()
		{
			++_tree;
			return (*this);
		}

		map_reverse_iterator operator--(int)
		{
			map_reverse_iterator temp = *this;
			_tree++;
			return temp;
		}

		bool operator!()
		{
			if (_tree == nullptr)
				return true;
			return false;
		}

		bool operator==(map_reverse_iterator const &rhs)
		{
			if (_tree == rhs._tree)
				return true;
			return false;
		}

		bool operator!=(map_reverse_iterator const &rhs)
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

	template <class pair, typename NodPtr>
	class MapIterator
	{
	public:
	public:
		NodPtr _tree;
		typedef pair value_type;

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
			_tree = get_precedent(_tree);
			return (*this);
		}

		MapIterator operator--(int)
		{
			MapIterator temp = *this;
			_tree = get_precedent(_tree);

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
		typedef map_reverse_iterator<iterator> reverse_iterator;
		typedef map_reverse_iterator<const_iterator> const_reverse_iterator;
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

		iterator begin()
		{
			iterator it(_avl.most_left(_tree));
			return (it);
		}
		key_compare key_comp() const
		{
			return key_compare();
		}
		const_iterator begin() const
		{
			const_iterator it(_avl.most_left(_tree));

			return (it);
		}

		reverse_iterator rbegin()
		{
			reverse_iterator it(end());
			return it;
		}

		const_reverse_iterator rbegin() const
		{
			const_reverse_iterator it(end());
			return it;
		}

		reverse_iterator rend()
		{
			reverse_iterator it(begin());
			return it;
		}

		const_reverse_iterator rend() const
		{
			const_reverse_iterator it(begin());
			return it;
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
		MapKeyCompare value_comp() const
		{
			return MapKeyCompare(m_comp);
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
			bool bl;

			NodePtr node = _avl.search_by_key(*position, bl, _tree);
			if (!bl || position == begin() || position == end())
				insert(val);
			else
			{
				iterator next = position++;
				iterator prec = position--;
				if (m_comp(next->first, val) && !m_comp(prec->first, val))
				{
					NodePtr no = position.base();
					node = _avl.insertNode2(no, val);
					_tree = _avl.balance_tree(_tree, val);
				}
			}
			return position;
		}

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				insert(*first);
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
			bool b = true;
			Node *pos = _avl.search_by_key(make_pair(k, mapped_type()), b, _tree);
			//  it(pos);
			erase(iterator(pos));
			// if(_tree->parent == end_tree )
			// std::cout << "hello" << std::endl;
			// exit(1);
			// _tree = );
			return 5;
		}

		void erase(iterator first, iterator last)
		{
			iterator temp;
			NodePtr ptr;
			bool bl;
			key_type a = first->first;
			key_type b = last->first;

			while (first->first != b)
			{
				if (first == end())
					return;
				temp = first;
				first++;
				ptr = _avl.newNode((first.base()->pair));
				erase(temp);
				first = iterator(_avl.search_by_key(ptr->pair, bl, _tree));
				// if (first->first == b)
				// {
				// 	std::cout << "l " << b << std::endl;
				// }
			}
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

		pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			pair<const_iterator, const_iterator> ret;

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

assigning to
'ft::map<char, int, std::__1::less<char>, std::__1::allocator<ft::pair<const char, int> > >::NodePtr
' (aka 'Node<pair<const char, int> > *') from incompatible
	  type 'Node<ft::pair<const char, int> >'
	node = _avl.insertNode2(position.base(), val);
											   ~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

*/