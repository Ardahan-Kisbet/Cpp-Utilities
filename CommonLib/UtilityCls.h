#pragma once
#include <string>
class UtilityCls
{
public:
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() :val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
	};

public:
	void Trim(char* src, size_t length);
	int strStr(std::string haystack, std::string needle);
};

