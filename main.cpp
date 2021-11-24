
#include <iostream>
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
		cout << "*" << root->height << "*" << root->key << endl;
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

int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) -
       height(N->right);
}

Node *insertNode(Node *root, int key)
{
	if (root == nullptr)
		return newNode(key);

	if (key < root->key)
		root->left = insertNode(root->left, key);
	else if (key > root->key)
		root->right = insertNode(root->right, key);
	
	root->height = max(height(root->left),  height(root->right)) + 1;
	int bf = getBalanceFactor(root);
	std::cout << "bf" << bf <<  std::endl;
	return root;
}

int main()
{
	Node *root = NULL;
	// root = newNode(10);
	root = insertNode(root, 33);
	root = insertNode(root, 13);
	// root = insertNode(root, 55);
	// root = insertNode(root, 2);
	//  root = insertNode(root, 1);
	// root = insertNode(root, 61);
	// root = insertNode(root, 8);
	// root = insertNode(root, 11);
	printTree(root, "", true);
	//   root = deleteNode(root, 13);
	//   cout << "After deleting " << endl;
	//   printTree(root, "", true);
}