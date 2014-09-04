/*
 * Filename:	MaximumDepthOfBinaryTree.cpp
 * Author:		fishpj
 * Date:		08/31/2014
 */

#include "leetCode.h"

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{
	}
};

class Solution
{
	public:
		int maxDepth(TreeNode *root)
		{
			 if (NULL == root)
			 {
				 return 0;
			 }
			 if ( NULL == root->left && NULL == root->right)
			 {
				 return 1;
			 }
			 else
			 {
				 int iMaxLeft = maxDepth(root->left);
				 int iMaxRight = maxDepth(root->right);
				 return (iMaxLeft > iMaxRight ? iMaxLeft:iMaxRight) + 1;
				 //注意这里出现了多重递归，虽然可以得到正确结果，但是在数据稍微大一点的时候就容易出现递归调用过多造成时间消耗
				 //return maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left)+1: maxDepth(root->right)+1;
			 }
		}
};

int main(int argc, char *argv[])
{
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	TreeNode tn4(4);
	tn1.left = &tn2;
	tn2.left = &tn3;
	tn3.left = &tn4;
	TreeNode tn5(5);
	TreeNode tn6(6);
	tn1.right = &tn5;
	tn5.right = &tn6;
	TreeNode tn7(7), tn8(8);
	tn6.right = &tn7;
	tn7.left = &tn8;
	Solution so;
	std::cout << so.maxDepth(&tn1) << std::endl;

	return 0;
}
