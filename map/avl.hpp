#include "map.hpp"

namespace ft
{



	template <typename T>
	class Node
	{
	public:
		Node *left;
		Node *right;
		int height;
		T pair;

		Node() : left(NULL), right(NULL), height(0) {}
		Node(Node<T> const &node)
		{
			left = node.left;
			right = node.right;
			height = node.height;
			pair = node.pair;
		}

		Node(T pair)
		{
			this->pair = pair;
			left = NULL;
			right = NULL;
			height = 0;
		}

	};

	template <class T, class Comp>
	class Avl
	{
	public:
		Node<T> *ptr;
		Comp comp;

	public:
		Avl(){};
		Avl(Comp &p) : ptr(nullptr) , comp(p) {};

		Avl(Node<T> &p) : ptr(&p){};
		T	&get_data()
		{
			return (ptr->pair);
		}

		Avl &operator++()
		{
			if (ptr->right) {
			ptr = ptr->right;
			while (ptr->left) {
				ptr = ptr->left;
			}
		} else {
			Node<T> y = ptr->parent;
			while (ptr == y->right) {
				ptr = y;
				y = y->parent;
			}
			if (ptr->right != y) {
				ptr = y;
			}
		}
			return (*this);
		}
		void printTree(Node<T> *ptr, std::string indent, bool last)
		{
			if (ptr != nullptr)
			{
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

		Node<T> *newNode(T pair)
		{
			Node<T> *node = new Node<T>();
			node->pair = pair;
			node->left = nullptr;
			node->right = nullptr;
			return node;
		}

		int max(int a, int b)
		{
			return (a > b ? a : b);
		}

		int height(Node<T> *root)
		{
			if (root == NULL)
				return 0;
			return (root->height);
		}

		Node<T> *right_rotate(Node<T> *y)
		{
			Node<T> *x;
			Node<T> *T2;

			x = y->left;
			T2 = x->right;

			x->right = y;
			y->left = T2;

			x->height = max(height(x->left), height(x->right)) + 1;
			y->height = max(height(y->left), height(y->right)) + 1;

			return x;
		}

		Node<T> *left_rotate(Node<T> *x)
		{
			Node<T> *y;
			Node<T> *T2;

			y = x->right;
			T2 = y->left;

			y->left = x;
			x->right = T2;

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
				return newNode(pair);

			if (comp(pair, root->pair))
				root->left = insertNode(root->left, pair);
			else if (comp(root->pair, pair))
				root->right = insertNode(root->right, pair);
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

		void insert(T pair)
		{
			ptr = insertNode(ptr, pair);
		}

		Node<T> *nodeWithMimumValue(Node<T> *node)
		{
			Node<T> *current = node;
			while (current->left != NULL)
				current = current->left;
			return current;
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
				if ((root->left == NULL) ||
					(root->right == NULL))
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
					root->key = temp->key;
					root->right = deleteNode(root->right,
											 temp->key);
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