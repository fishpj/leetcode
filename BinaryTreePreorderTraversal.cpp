/*
 * Filename:	BinaryTreePreorderTraversal.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"
#include <vector>
#include <stack>
using std::vector;
using std::stack;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution
{
	public:
		vector<int> preorderTraversal(TreeNode *root)
		{
			vector<int> ivec;
			stack<TreeNode*> tnStack;
			tnStack.push(root);
			struct TreeNode* tnTop = tnStack.top();
			while (!tnStack.empty())
			{
				if (NULL == tnTop)
				  return ivec;
				root = tnStack.top();
				ivec.push_back(root->val);
				tnStack.pop();
				if (root->right)
					tnStack.push(root->right);
				if (root->left)
					tnStack.push(root->left);
			}
			return ivec; 
		}
};

int main(int argc, char *argv[])
{
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	TreeNode tn4(4);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn3.right = &tn4;

	Solution so;
	std::cout << (so.preorderTraversal(&tn1))[0] << std::endl;
	std::cout << (so.preorderTraversal(&tn1))[1] << std::endl;
	std::cout << (so.preorderTraversal(&tn1))[2] << std::endl;
	std::cout << (so.preorderTraversal(&tn1))[3] << std::endl;
	return 0;
}
