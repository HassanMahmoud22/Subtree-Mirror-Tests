#include <iostream>
using namespace std;
template<class type>
class BSTFCI
{
public:
	class BSTNode
	{
	public:
		BSTNode* left;
		BSTNode* right;
		type data;

	};
	BSTNode* root;
	BSTNode* newNode;
	BSTNode* current;
	BSTNode* trailCurrent;

	BSTFCI()
	{
		root = NULL;
	}
	void insert(type value)
	{
		newNode = new BSTNode;
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		if (root == NULL)
			root = newNode;
		else
		{
			current = root;
			while (current != NULL)
			{
				trailCurrent = current;
				if (current->data == value)
				{
					cerr << "The insert item is already in the list-";
					cerr << "duplicates are not allowed." << value << endl;
					return;
				}
				else if (current->data > value)
					current = current->left;
				else
					current = current->right;
			}
			if (trailCurrent->data > value)
				trailCurrent->left = newNode;
			else
				trailCurrent->right = newNode;
		}
	}

	bool isBalanced(BSTNode* theRoot)
	{
		int lh;
		int rh;


		if (theRoot == NULL)
			return 1;

		lh = height(theRoot->left);
		rh = height(theRoot->right);

		if (abs(lh - rh) <= 1 && isBalanced(theRoot->left) && isBalanced(theRoot->right))
			return 1;


		return 0;
	}

	int max(int a, int b)
	{
		return (a >= b) ? a : b;
	}

	int height(BSTNode* node)
	{
		if (node == NULL)
			return 0;

		return 1 + max(height(node->left), height(node->right));
	}
	void testBAlance()
	{
		int num = 0, input = 0;
		cout << "welcome to the Balance test" << endl;
		cout << "please enter the number of nodes of the tree" << endl;
		cin >> num;
		cout << "please enter the  "<< num << " nodes of the tree" << endl;
		for (int i = 0;i < num; i++)
		{
			cin >> input;
			insert(input);
		}
		if (isBalanced(root))
		{
			cout << "it's balanced tree" << endl;
		}
		else
		{
			cout << "it's not balanced tree" << endl;
		}
	}
	friend bool areIdentical(BSTNode* root1, BSTNode* root2)
	{
		if (root1 == NULL && root2 == NULL)
			return true;

		if (root1 == NULL || root2 == NULL)
			return false;

		return (root1->data == root2->data &&
			areIdentical(root1->left, root2->left) &&
			areIdentical(root1->right, root2->right));
	}

	friend bool isSubtree(BSTNode* T, BSTNode* S)
	{
		if (S == NULL)
			return true;

		if (T == NULL)
			return false;

		if (areIdentical(T, S))
			return true;

		return isSubtree(T->left, S) ||
			isSubtree(T->right, S);
	}

	void printRange(int min, int max , BSTNode* position)
	{
		if (position == NULL)
			return;
		if (min < position->data)
			printRange( min, max , position->left);

		if (min <= position->data && max >= position->data)
			cout << position->data << " ";

		if (max > position->data)
			printRange(min, max, position->right);
	}

	void flip(BSTNode* node)
	{
		if (node == NULL)
			return;
		else
		{
			BSTNode* temp;

			/* do the subtrees */
			flip(node->left);
			flip(node->right);

			/* swap the pointers in this node */
			temp = node->left;
			node->left = node->right;
			node->right = temp;
		}
	}
	void print(BSTNode* node)
	{
		if (node == NULL)
			return;

		print(node->left);
		cout << node->data << " ";
		print(node->right);
	}
};
int main()
{
	BSTFCI<int> obj, obj1, obj2, obj3, obj4;
	BSTFCI<int>::BSTNode* node1;
	BSTFCI<int>::BSTNode* node2;
    BSTFCI<int>::BSTNode* node3;
    BSTFCI<int>::BSTNode* node4;

	obj.testBAlance();

	int num = 0, input = 0 , min = 0 , max = 0;
	cout << "welcome to test if the tree is subtree of another one" << endl;
	cout << "Enter number of nodes of first tree" << endl;
	cin >> num;
	cout << "Enter the " << num << " nodes of the tree "<< endl;
	for (int i = 0;i < num; i++)
	{
		cin >> input;
		obj1.insert(input);
	}
	cout << "Enter number of nodes of second tree" << endl;
	cin >> num;
	cout << "Enter the " << num << " nodes of the tree " << endl;
	for (int i = 0;i < num; i++)
	{
		cin >> input;
		obj2.insert(input);
	}
	node1 = obj1.root;
	node2 = obj2.root;
	if (isSubtree(node1, node2))
	{
		cout << "it's subtree" << endl;
	}
	else
	{
		cout << "not subtree" << endl;
	}

    cout << "welcome to test the range of the tree" << endl;
	cout << "Enter number of nodes of first tree" << endl;
	cin >> num;
	cout << "Enter the " << num << " nodes of the tree " << endl;
	for (int i = 0;i < num; i++)
	{
		cin >> input;
		obj3.insert(input);
	}
	cout << "Enter the first number " << endl;
	cin >> min;
	cout << "Enter the second number " << endl;
	cin >> max;
	node3 = obj3.root;
	obj3.printRange(min, max, node3);

	cout << "welcome to the mirror test" << endl;
	cout << "Enter number of nodes of first tree" << endl;
	cin >> num;
	cout << "Enter the " << num << " nodes of the tree " << endl;
	for (int i = 0;i < num; i++)
	{
		cin >> input;
		obj4.insert(input);
	}
	node4 = obj4.root;
	obj4.print(node4);
	obj4.flip(node4);
	obj4.print(node4);
    return 0;
}
