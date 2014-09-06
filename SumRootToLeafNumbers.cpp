/*
 * Filename:	SumRootToLeafNumbers.cpp
 * Author:		fishpj
 * Date:		09/05/2014
 */

#include "leetCode.h"


class Solution
{
	public:
		//采用递归完成
		int recursiveSum(TreeNode *root, int sum)
		{
			if (nullptr == root)
			  return 0;
			if (nullptr == root->left && nullptr == root->right)
			  return root->val + 10*sum;
			return recursiveSum(root->left, 10*sum+root->val) + recursiveSum(root->right, 10*sum+root->val);
		}
		int sumNumbers(TreeNode *root)
		{
			return recursiveSum(root, 0); 
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
	tn2.right = &tn4;

	Solution so;

	std::cout << so.sumNumbers(&tn1) << std::endl;
	return 0;
}
