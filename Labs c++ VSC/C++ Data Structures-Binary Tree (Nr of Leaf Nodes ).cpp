#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node
{
	int data;
	struct node* left;
	struct node* right;
};


int getLeafCount(struct node* node)
{
	if (node == NULL)
		return 0;
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return getLeafCount(node->left) +
		getLeafCount(node->right);
}

struct node* nyNode(int data)
{
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return(node);
}
//
//int main()
//{
//	struct node* root = nyNode(1);
//	root->left = nyNode(2);
//	root->right = nyNode(3);
//	root->left->left = nyNode(4);
//	root->left->right = nyNode(5);
//
//	cout << "nr of Leaf in tree  : " <<
//		getLeafCount(root) << endl;
//	return 0;
//}
