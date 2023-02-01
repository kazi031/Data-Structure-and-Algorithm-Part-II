#include <cstddef>
class Node
{
public:
	int val;
	Node* left;
	Node* right;
	Node* parent;
	Node(int v)
	{
		val = v;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};