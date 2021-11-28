#include <iostream>
#include "vector/vector.hpp"
#include <vector>
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
	return (root->height) ;
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


int getBalanceFactor(Node *N) {
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

	root->height = max(height(root->left),  height(root->right)) + 1;
	int bf = getBalanceFactor(root);
	
	if (bf > 1) {
    if (key < root->left->key) {
      return right_rotate(root);
    } else if (key > root->left->key) {
      root->left = left_rotate(root->left);
      return right_rotate(root);
    }
  }
  if (bf < -1) {
    if (key > root->right->key) {
      return left_rotate(root);
    } else if (key < root->right->key) {
      root->right = right_rotate(root->right);
      return left_rotate(root);
    }
  }
	return root;
}


int main () {
	
	ft::vector<int> vec;

	vec.push_back(10);
	vec.push_back(4);
	vec.push_back(9);
	vec.push_back(3);
	vec.push_back(2);

	ft::vector<int> vec2;

	vec2.push_back(10);
	vec2.push_back(6);
	vec2.push_back(9);
	vec2.push_back(3);
	vec2.push_back(2);


	if (vec < vec2)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
  return 0;
}