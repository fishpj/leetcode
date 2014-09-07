/*
 * Filename:	MinimumDepthOfBinaryTree.cpp
 * Author:		fishpj
 * Date:		09/07/2014
 */

#include "leetCode.h"
#include <cmath>
using std::min;

class Solution
{
	public:
		int minDepth(TreeNode *root)
		{
			if (nullptr == root)
			  return 0;
			if (nullptr == root->left && nullptr == root->right)
			  return 1;
			else
			{
				//左右子树都不为空
				if (root->left && root->right)
					return (min(minDepth(root->left), minDepth(root->right))+1);
				//右子树为空，左边查找
				else if (root->left)
				  return minDepth(root->left) + 1;
				//左子树为空，右边查找
				else
				  return minDepth(root->right)+1;
			}
		}
};

int main(int argc, char *argv[])
{
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	TreeNode tn4(4);
	TreeNode tn5(5);
	tn1.left = &tn2;
	tn1.right = &tn3;
	tn2.left = &tn4;
	tn3.right = &tn5;

	Solution so;
	std::cout << so.minDepth(&tn1) << std::endl;
}
