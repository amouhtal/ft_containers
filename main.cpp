#include <iostream>
#include "vector/vector.hpp"
#include <vector>
#include <utility>
using namespace std;

class Node
{
public:
	Node *left;
	Node *right;
	int height;
	int key;
};

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

Node *newNode(int key)
{
	Node *node = new Node();
	node->key = key;
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

Node *insertNode(Node *root, int key)
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

int main()
{
	  ft::vector<int> v;
  v.resize(6);
    for (ft::pair<size_t, ft::vector<int>::const_reverse_iterator> i(0, v.rbegin()); i.first < v.size(); ++i.first)
        std::cout << i.second[i.first] << " | ";
	// std::pair<std::string, double> product1;				   // default constructor
	// std::pair<std::string, double> product2("tomatoes", 2.30); // value init
	// std::pair<std::string, double> product3(product2);		   // copy constructor

	// product1 = std::make_pair(std::string("lightbulbs"), 0.99); // using make_pair (move)

	// product2.first = "shoes"; // the type of first is string
	// product2.second = 39.90;  // the type of second is double
    // for (std::pair<size_t, typename T::const_reverse_iterator> i(0, cont.rbegin()); i.first < cont.size(); ++i.first)
    //     std::cout << i.second[i.first] << " | ";
	// std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	// std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	// std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
	return 0;
}