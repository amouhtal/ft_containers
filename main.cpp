#include <iostream>
#include "vector/vector.hpp"
#include <vector>
#include <utility>
using namespace std;

template <typename K, typename T, typename Compare = std::less<K> >
class MapKeyCompare : std::binary_function<std::pair<K, T>, std::pair<K, T>, bool>
{
public:
	typedef typename std::pair<K, T> value_type;

private:
	Compare comp;

public:
	MapKeyCompare(Compare const &comp = Compare()) : comp(comp) {}
	virtual ~MapKeyCompare() {}

	bool operator()(const value_type &a, const value_type &b) const
	{
		return (comp(a.first, b.first));
	}
	bool operator()(const value_type &a, const K &b) const
	{
		return (comp(a.first, b));
	}
	bool operator()(const K &a, const value_type &b) const
	{
		return (comp(a, b.first));
	}
};

template <typename T>
class Node
{
public:
	Node *left;
	Node *right;
	int height;
	T pair;
};

template <typename T, typename Comp>
class Avl
{
private:
	Node<T> *ptr;

public:
	void printTree(Node *root, string indent, bool last)
	{
		if (root != nullptr)
		{
			cout << indent;
			if (last)
			{
				cout << "R----";
				indent += "   ";
			}
			else
			{
				cout << "L----";
				indent += "|  ";
			}
			cout << root->key << endl;
			printTree(root->left, indent, false);
			printTree(root->right, indent, true);
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

	int height(Node *root)
	{
		if (root == NULL)
			return 0;
		return (root->height);
	}

	Node *right_rotate(Node *y)
	{
		Node *x;
		Node *T;

		x = y->left;
		T = x->right;

		x->right = y;
		y->left = T;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return x;
	}

	Node *left_rotate(Node *x)
	{
		Node *y;
		Node *T;

		y = x->right;
		T = y->left;

		y->left = x;
		x->right = T;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalanceFactor(Node *N)
	{
		if (N == NULL)
			return 0;
		return (height(N->left) - height(N->right));
	}

	Node<T> *insertNode(Node<T> *root, T pair)
	{
		if (root == nullptr)
			return newNode(key);

		if (key < root->key)
			root->left = insertNode(root->left, key);
		else if (key > root->key)
			root->right = insertNode(root->right, key);
		else
			return root;

		root->height = max(height(root->left), height(root->right)) + 1;
		int bf = getBalanceFactor(root);

		if (bf > 1)
		{
			if (key < root->left->key)
			{
				return right_rotate(root);
			}
			else if (key > root->left->key)
			{
				root->left = left_rotate(root->left);
				return right_rotate(root);
			}
		}
		if (bf < -1)
		{
			if (key > root->right->key)
			{
				return left_rotate(root);
			}
			else if (key < root->right->key)
			{
				root->right = right_rotate(root->right);
				return left_rotate(root);
			}
		}
		return root;
	}

	Node *nodeWithMimumValue(Node *node)
	{
		Node *current = node;
		while (current->left != NULL)
			current = current->left;
		return current;
	}

	Node *deleteNode(Node *root, int key)
	{
		// Find the node and delete it
		if (root == NULL)
			return root;
		if (key < root->key)
			root->left = deleteNode(root->left, key);
		else if (key > root->key)
			root->right = deleteNode(root->right, key);
		else
		{
			if ((root->left == NULL) ||
				(root->right == NULL))
			{
				Node *temp = root->left ? root->left : root->right;
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
				Node *temp = nodeWithMimumValue(root->right);
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


int main()
{
	std::map<std::string, int> mapOfWordCount;
	// Insert Element in map
	mapOfWordCount.insert(std::pair<std::string, int>("first", 1));
	mapOfWordCount.insert(std::pair<std::string, int>("second", 2));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 3));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 4));
	mapOfWordCount.insert(std::pair<std::string, int>("third", 5));
	// Create a map iterator and point to beginning of map
	std::map<std::string, int>::iterator it = mapOfWordCount.begin();
	// Iterate over the map using Iterator till end.
	while (it != mapOfWordCount.end())
	{
		// Accessing KEY from element pointed by it.
		std::string word = it->first;
		// Accessing VALUE from element pointed by it.
		int count = it->second;
		std::cout << word << " :: " << count << std::endl;
		// Increment the Iterator to point to next entry
		it++;
	}
	return 0;
}