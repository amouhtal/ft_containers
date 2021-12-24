#include "map.hpp"
#include "../vector/utils/utils.hpp"

namespace ft
{

	template <typename T>
	class Node
	{
	public:
		Node *left;
		Node *right;
		Node *parent;

		int height;
		T pair;

		Node() : left(NULL), right(NULL), height(0), parent(nullptr) {}

		Node(Node<T> const &node) : pair(node.pair)
		{
			left = node.left;
			right = node.right;
			height = node.height;
			parent = node.parent;
			// pair = node.pair;
		}

		Node(T const &pair) : pair(pair)
		{
			// this->pair = pair;
			left = NULL;
			right = NULL;
			parent = NULL;
			height = 1;
		}

		// Node<T> &operator=(Node<T> const &rhs)
		// {
		// 	if (this != &rhs)
		// 	{
		// 		left = rhs.left;
		// 		right = rhs.right;
		// 		parent = rhs.parent;
		// 		height = rhs.height;
		// 		pair = rhs.pair;
		// 	}
		// 	return *this;
		// }

		bool operator==(Node<T> const &rhs)
		{
			if (left == rhs.left && right == rhs.right && parent == rhs.parent && height == rhs.height)
				return true;
			return false;
		}

		bool operator!=(Node<T> const &rhs)
		{
			if (left == rhs.left && right == rhs.right && parent == rhs.parent && height == rhs.height)
				return false;
			return true;
		}
	};

	template <typename nodePtr>
	nodePtr get_next(nodePtr root)
	{
		if (root->right)
		{
			root = root->right;
			while (root->left)
			{
				root = root->left;
			}
		}
		else
		{
			nodePtr y = root->parent;
			while (root == y->right)
			{
				root = y;
				y = y->parent;
			}
			if (root->right != y)
			{
				root = y;
			}
		}
		return (root);
	}

	template <typename nodePtr>
	nodePtr get_precedent(nodePtr root)
	{
		if (root->left)
		{
			nodePtr y = root->left;
			while (y->right)
			{
				y = y->right;
			}
			root = y;
		}
		else
		{
			nodePtr y = root->parent;
			while (root == y->left)
			{
				root = y;
				y = y->parent;
			}
			root = y;
		}
		return root;
	}
	template <class T, class Comp, typename Alloc = std::allocator<T> >
	class Avl
	{
	public:
		// typedef Alloc allocator_type;
		typedef Node<T> mynode;
		typedef typename Alloc::template rebind<Node<T> >::other allocator_type;
		Node<T> *ptr;
		Comp comp;
		allocator_type m_allocate;

	public:
		Avl(const allocator_type &alloc = allocator_type()) : ptr(nullptr), m_allocate(alloc){};
		Avl(Comp &p, const allocator_type &alloc = allocator_type()) : ptr(nullptr), comp(p), m_allocate(alloc){};

		Avl(Node<T> &p) : ptr(p)
		{
			// std::cout << ptr->pair.first << "<-- here\n";
		}

		size_t size2(Node<T> *root)
		{
			size_t ret = 1;
			if (root == NULL)
				return 0;

			if (root->left)
				ret += size2(root->left);
			if (root->right)
				ret += size2(root->right);
			return ret;
		}

		Node<T> *clear2(Node<T> *root)
		{
			if (root == NULL)
				return NULL;
			if (root->left)
			{
				clear2(root->left);
				m_allocate.deallocate(root->left, 1);
				root->left = NULL;
				root->parent = NULL;
			}
			if (root->right)
			{
				clear2(root->right);
				m_allocate.deallocate(root->right, 1);
				root->right = NULL;
				root->parent = NULL;
			}
			return NULL;
		}

		T &get_data()
		{
			return (ptr->pair);
		}

		Node<T> *most_left(Node<T> *ptr2) const
		{
			Node<T> *tmp = ptr2;
			while (tmp && tmp->left)
				tmp = tmp->left;
			return tmp;
		}

		Node<T> *most_right(Node<T> *ptr2) const
		{
			Node<T> *tmp = ptr2;
			while (tmp && tmp->parent)
				tmp = tmp->parent;
			return tmp;
		}

		void printTree(Node<T> *ptr, std::string indent, bool last)
		{
			if (ptr != nullptr)
			{
				// if (ptr->parent)
				// 	std::cout << "\tp: " << ptr->parent->pair.first;
				std::cout << indent;
				if (last)
				{
					std::cout << "R----";
					indent += "   ";
				}
				else
				{
					std::cout << "L----";
					indent += "|  ";
				}
				std::cout << ptr->pair.first << std::endl;
				printTree(ptr->left, indent, false);
				printTree(ptr->right, indent, true);
			}
		}

		Node<T> *newNode(T const &pair)
		{
			Node<T> *node = m_allocate.allocate(1);
			m_allocate.construct(node, pair);
			// node->pair = pair;
			node->parent = nullptr;
			node->left = nullptr;
			node->right = nullptr;
			node->height = 1;
			return node;
		}

		int max(int a, int b) const
		{
			return (a > b ? a : b);
		}

		int height(Node<T> *root) const
		{
			if (root == NULL)
				return 0;
			return (root->height);
		}

		Node<T> *right_rotate(Node<T> *y)
		{
			Node<T> *x;
			Node<T> *T2;
			Node<T> *temp_parent;
			x = y->left;
			T2 = x->right;

			temp_parent = y->parent;
			y->parent = x;
			x->right = y;
			x->parent = temp_parent;
			y->left = T2;
			if (T2)
				T2->parent = y;
			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;

			return x;
		}

		Node<T> *left_rotate(Node<T> *x)
		{
			Node<T> *y;
			Node<T> *T2;
			Node<T> *temp_parent;
			y = x->right;
			T2 = y->left;

			temp_parent = x->parent;
			x->parent = y;
			y->left = x;
			y->parent = temp_parent;

			x->right = T2;
			if (T2)
				T2->parent = x;

			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;

			return y;
		}

		int getBalanceFactor(Node<T> *N)
		{
			if (N == NULL)
				return 0;
			return (height(N->left) - height(N->right));
		}

		Node<T> *insertNode(Node<T> *root, T pair)
		{
			if (root == nullptr)
			{
				return newNode(pair);
			}
			if (comp(pair, root->pair))
			{
				Node<T> *ret = insertNode(root->left, pair);
				ret->parent = root;
				root->left = ret;
			}
			else if (comp(root->pair, pair))
			{
				Node<T> *ret = insertNode(root->right, pair);
				ret->parent = root;
				root->right = ret;
			}
			else
				return root;
			root->height = max(height(root->left), height(root->right)) + 1;
			int bf = getBalanceFactor(root);

			if (bf > 1)
			{
				if (comp(pair, root->left->pair))
				{
					return right_rotate(root);
				}
				else if (comp(root->left->pair, pair))
				{

					root->left = left_rotate(root->left);

					return right_rotate(root);
				}
			}
			if (bf < -1)
			{
				if (comp(root->right->pair, pair))
				{
					return left_rotate(root);
				}
				else if (comp(pair, root->right->pair))
				{
					root->right = right_rotate(root->right);
					return left_rotate(root);
				}
			}
			return root;
		}

		Node<T> *insertNode2(Node<T> *root, const T &pair)
		{
			if (root == nullptr)
			{
				return newNode(pair);
			}
			if (comp(pair, root->pair))
			{
				Node<T> *ret = insertNode(root->left, pair);
				ret->parent = root;
				root->left = ret;
			}
			else if (comp(root->pair, pair))
			{
				Node<T> *ret = insertNode(root->right, pair);
				ret->parent = root;
				root->right = ret;
			}
			else
				return root;

			return root;
		}

		Node<T> *balance_tree(Node<T> *root, T pair)
		{
			if (root == nullptr)
				return nullptr;
			if (comp(pair, root->pair))
				Node<T> *ret = balance_tree(root->left, pair);
			else if (comp(root->pair, pair))
				Node<T> *ret = insertNode(root->right, pair);
			else
				return root;

			root->height = max(height(root->left), height(root->right)) + 1;
			int bf = getBalanceFactor(root);

			if (bf > 1)
			{
				if (comp(pair, root->left->pair))
				{
					return right_rotate(root);
				}
				else if (comp(root->left->pair, pair))
				{
					root->left = left_rotate(root->left);
					return right_rotate(root);
				}
			}
			if (bf < -1)
			{

				if (comp(root->right->pair, pair))
				{
					return left_rotate(root);
				}
				else if (comp(pair, root->right->pair))
				{
					root->right = right_rotate(root->right);
					return left_rotate(root);
				}
			}
			return root;
		}

		// void insert(T pair)
		// {
		// 	ptr = insertNode(ptr, pair);
		// }

		Node<T> *search_by_key(T pair, bool &bl, Node<T> *ptr2)
		{
			Node<T> *tmp;
			tmp = ptr2;

			while (1 && tmp)
			{
				if (tmp->pair.first == pair.first)
				{
					bl = true;
					return (tmp);
				}
				if (comp(tmp->pair, pair))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			Node<T> *ret = newNode(pair);
			return (ret);
		}

		Node<T> *nodeWithMimumValue(Node<T> *node)
		{
			Node<T> *current = node;
			while (current->left != NULL)
				current = current->left;
			return current;
		}

		bool count(Node<T> *root, T pair) const
		{
			Node<T> *tmp;
			tmp = root;

			while (1 && tmp)
			{
				if (tmp->pair.first == pair.first)
				{
					return (true);
				}
				if (comp(tmp->pair, pair))
					tmp = tmp->right;
				else
					tmp = tmp->left;
			}
			return false;
		}

		Node<T> *deleteNode(Node<T> *root, T key)
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (comp(key, root->pair))
				root->left = deleteNode(root->left, key);
			else if (comp(root->pair, key))
				root->right = deleteNode(root->right, key);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					Node<T> *temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						// std::cout << "root : " << temp->pair.first << std::endl;
						temp = root;
						root = NULL;
					}
					else
					{
						// *root = *temp;
						Node<T> *temp1 = root->parent;
						m_allocate.construct(root, temp->pair);
						root->left = temp->left;
						root->right = temp->right;
						root->height = temp->height;
						// root->pair = temp->pair;
						root->parent = temp1;
					}
					m_allocate.destroy(temp);
					m_allocate.deallocate(temp, 1);
					// free(temp);
				}
				else
				{
					Node<T> *temp = nodeWithMimumValue(root->right);

					Node<T> *new_node = m_allocate.allocate(1);
					m_allocate.construct(new_node, temp->pair);
					// root->left = new_node->left;
					// root->right = new_node->right;
					// root->parent = new_node->parent;
					// root->height = new_node->height;
					new_node->parent = root->parent;
					new_node->left = root->left;
					new_node->right = root->right;
					new_node->height = root->height;

					if (root->left)
						root->left->parent = new_node;
					if (root->right)
						root->right->parent = new_node;

					if (root == root->parent->left)
						root->parent->left = new_node;
					else if (root == root->parent->right)
						root->parent->right = new_node;
					// if (root-)
					root->left = nullptr;
					root->right = nullptr;
					root->parent = nullptr;
					// m_allocate.construct(root, temp->pair);
					root = new_node;
					// root->pair = temp->pair;
					root->right = deleteNode(root->right, temp->pair);
				}
			}
			if (root == NULL)
				return root;
			// Update the balance factor of each node and
			// balance the tree
			root->height = 1 + max(height(root->left),
								   height(root->right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (getBalanceFactor(root->left) >= 0)
				{
					return right_rotate(root);
				}
				else
				{
					root->left = left_rotate(root->left);
					return right_rotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (getBalanceFactor(root->right) <= 0)
				{
					return left_rotate(root);
				}
				else
				{
					root->right = right_rotate(root->right);
					return left_rotate(root);
				}
			}
			return root;
		}

		Node<T> *eraseNode(Node<T> *root, T key)
		{
			// Find the node and delete it
			if (root == NULL)
				return root;
			if (comp(key, root->pair))
				root->left = deleteNode(root->left, key);
			else if (comp(root->pair, key))
				root->right = deleteNode(root->right, key);
			else
			{
				if ((root->left == NULL) || (root->right == NULL))
				{
					Node<T> *temp = root->left ? root->left : root->right;
					if (temp == NULL)
					{
						temp = root;
						root = NULL;
					}
					else
						*root = *temp;
					free(temp);
				}
				else
				{
					Node<T> *temp = nodeWithMimumValue(root->right);
					root->pair = temp->pair;
					root->right = deleteNode(root->right, temp->pair);
				}
			}
			if (root == NULL)
				return root;

			// Update the balance factor of each node and
			// balance the tree
			root->height = 1 + max(height(root->left),
								   height(root->right));
			int balanceFactor = getBalanceFactor(root);
			if (balanceFactor > 1)
			{
				if (getBalanceFactor(root->left) >= 0)
				{
					return right_rotate(root);
				}
				else
				{
					root->left = left_rotate(root->left);
					return right_rotate(root);
				}
			}
			if (balanceFactor < -1)
			{
				if (getBalanceFactor(root->right) <= 0)
				{
					return left_rotate(root);
				}
				else
				{
					root->right = right_rotate(root->right);
					return left_rotate(root);
				}
			}
			return root;
		}
	};
}