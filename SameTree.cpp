/*
 * Filename:	SameTree.cpp
 * Author:		fishpj
 * Date:		09/01/2014
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
		bool isSameTree(TreeNode *p, TreeNode *q)
		{
			if (NULL != p && NULL != q)
			{
				return p->val == q->val&& isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
			}
			else if (NULL == p && NULL == q)
			  return true;
			else
			  return false;
		}
};

int main(int argc, char *argv[])
{
	TreeNode tp1(1);
	TreeNode tq1(1);
	TreeNode tp2(2);
	TreeNode tq2(2);
	TreeNode tp3(3);
	TreeNode tq3(3);
	//tp1.left = &tp2;
	//tp1.right = &tp3;
	//tq1.left = &tq2;
	//tq1.right = &tq3;

	Solution so;
	std::cout << so.isSameTree(&tp1, &tp2) << std::endl;

	return 0;
}
