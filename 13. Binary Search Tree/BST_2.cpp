#include <iostream>
#include <queue>

// A node class representing nodes in a Binary Search Tree
class Node {
	public:
		int data;
		Node *left;
		Node *right;
		// default constructor
		Node() {
			data = 0;
			left = NULL;
			right = NULL;
		}
		// parameterized constructor
		Node(int n) {
			data = n;
			left = NULL;
			right = NULL;
		}
};

// Binary Search Tree (BST)
class BinarySearchTree {
	// root node pointer
	public:
		Node *root;
		Node* insert(Node *root, int data);
		int height(Node *root);
		void levelOrder(Node *root);
};

Node* BinarySearchTree::insert(Node *root, int data) {
	// if the root node pointer is not null, insert nodes
	if (root != NULL) {
		if (data <= root->data) {
			root->left = insert(root->left, data);
		} else {
			root->right = insert(root->right, data);
		}
	} else {
	    // root node pointer is null so create a new Node
	    return new Node(data);
	}
	// return the root node pointer
	return root;
}

int BinarySearchTree::height(Node *root) {
	// if root node is null, tree height is 0
	if (root == NULL) {
	    return -1;
	} else {
	    // recursively check the height of left and right subtrees
	    // along the longest root-to-leaf path
	    int leftSubTreeDepth = height(root->left);
	    int rightSubTreeDepth = hight(root->right);

	    // compare sub tree root-to-leaf paths and add 1 to account for the root node
	    return std::max(leftSubTreeDepth, rightSubTreeDepth) + 1;
	}
}

void BinarySearchTree::levelOrder(Node *root) {
	// create a queue (FIFO) to stored Node* pointers
	std::queue<Node*> q;
	Node *temp = root;
	// if the root node pointer is not null
	if (root != NULL) {
		// add it to the queue
		q.push(root);
	}

	// while the queue is not empty, use the stored Node* pointers
	while(!q.empty()) {
		// print node values to std out
		std::cout << temp -> data << " ";

		// add left/right child nodes to queue if they exist
		if (temp->left != NULL) q.push(temp->left);
		if (temp->right != NULL) q.push(temp->right);

		// pop element from the front of queue (e.g. remove element at the front of queue)
		q.pop();

		// set the temp root node pointer to be the new front of the queue
		temp = q.front();
	}
}

int main() {
	BinarySearchTree bst;
	Node *root = NULL;

	// 3 5 2 1 4 6 7
	int treeOne[] = {3, 5, 2, 1, 4, 6, 7 };
	// tree 1 - longest root-to-leaf path is 4 nodes connected by 3 edges, the tree tree height is 3
	/*
	       3
             /  \
            2    5
           /    /  \
          1    4    6
           	     \
	               7
	*/

	// iterate the integer array and insert nodes into tree
	for (int i = 0; i < sizeof(treeOne) / sizeof(treeOne[0]); i++) {
		root = bst.insert(root, treeOne[i]);
	}

	// Level Order Traversal (traverse the tree level by level going from leftmost node to right
	std::cout << "Level Order Traversal" << std::endl;
	bst.levelOrder(root);
	std::cout << std::endl;
  	// 3 2 5 1 4 6 7 

	// Max Height of Binary Search Tree
	std::cout << "Tree Height: " << bst.height(root) << std::endl;
  	// 3

	// tree 2
	Node *temp;
	BinaryTree bst;
	// 4 2 6 1 3 5 7
	int treeTwo[] = {4,2,6,1,3,5,7};
  
	for (int i = 0; i < sizeof(treeTwo) / sizeof(treeTwo[0]); i++) {
		temp = bst.insert(temp, treeTwo[i]);
	}
  
	std::cout << "Level order traversal: " << std::endl;
	bst.levelOrder(temp);
	std::cout << std::endl;
  	// 4 2 6 1 3 5 7 
  
	std::cout << "Tree Height: " << bst.height(temp) << std::endl;
  	// 2

	return 0;
}