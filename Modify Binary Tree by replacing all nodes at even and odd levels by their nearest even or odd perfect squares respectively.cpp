// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Structure of a
// Binary Tree Node
struct Node {
	int data;
	struct Node *left, *right;
};

// Function to replace all nodes
// at even and odd levels with their
// nearest even or odd perfect squares
void LevelOrderTraversal(Node* root)
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue
	// for level order traversal
	queue<Node*> q;

	// Enqueue root
	q.push(root);

	// Initialize height
	int lvl = 1;

	// Iterate until queue is not empty
	while (q.empty() == false) {

		// Store the size
		// of the queue
		int n = q.size();

		// Traverse in range [1, n]
		for (int i = 0; i < n; i++) {

			// Store the current node
			Node* node = q.front();

			// Store its square root
			double num = sqrt(node->data);
			int x1 = floor(num);
			int x2 = ceil(num);

			// Check if it is a perfect square
			if (x1 == x2) {

				// If level is odd and value is even,
				// find the closest odd perfect square
				if ((lvl & 1) && !(x1 & 1)) {

					int num1 = x1 - 1, num2 = x1 + 1;

					node->data
						= (abs(node->data - num1 * num1)
						< abs(node->data - num2 * num2))
							? (num1 * num1)
							: (num2 * num2);
				}

				// If level is even and value is odd,
				// find the closest even perfect square
				if (!(lvl & 1) && (x1 & 1)) {

					int num1 = x1 - 1, num2 = x1 + 1;

					node->data
						= (abs(node->data - num1 * num1)
						< abs(node->data - num2 * num2))
							? (num1 * num1)
							: (num2 * num2);
				}
			}

			// Otherwise, find the find
			// the nearest perfect square
			else {
				if (lvl & 1)
					node->data
						= (x1 & 1) ? (x1 * x1) : (x2 * x2);
				else
					node->data
						= (x1 & 1) ? (x2 * x2) : (x1 * x1);
			}

			// Print front of queue
			// and remove it from queue
			cout << node->data << " ";
			q.pop();

			// Enqueue left child
			if (node->left != NULL)
				q.push(node->left);

			// Enqueue right child
			if (node->right != NULL)
				q.push(node->right);
		}

		// Increment the level by 1
		lvl++;
		cout << endl;
	}
}

// Utility function to
// create a new tree node
Node* newNode(int data)
{
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver Code
int main()
{
	// Binary Tree
	Node* root = newNode(5);
	root->left = newNode(3);
	root->right = newNode(2);
	root->right->left = newNode(16);
	root->right->right = newNode(19);

	LevelOrderTraversal(root);

	return 0;
}
