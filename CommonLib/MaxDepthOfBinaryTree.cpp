#include <algorithm>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};


// Find Max Depth of a Binary Tree (LinkedList)
int MaximumDepthOfBinaryTree(TreeNode* root)
{
	// We can traverse binary tree preorder while calculating the levels recursively

	// null check
	if (root == nullptr)
		return 0;

	// this node itself count as 1
	int count = 1;

	// check depths of left and right childs then get the maximum among them
	count += std::max(MaximumDepthOfBinaryTree(root->left), MaximumDepthOfBinaryTree(root->right));

	//max(maxDepth(root->left), maxDepth(root->right))

	return count;
}