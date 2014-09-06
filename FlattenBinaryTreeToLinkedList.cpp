/*
 * Filename:	FlattenBinaryTreeToLinkedList.cpp
 * Author:		fishpj
 * Date:		09/06/2014
 */

#include "leetCode.h"
#include <deque>

using std::deque;
class Solution
{
	public:
		//通过递归先序遍历二叉树并将其存入队列中进行处理
		void recursiveTraversal(TreeNode *root, deque<TreeNode *> &tnDeque)
		{
			if (nullptr == root)
			  return;
			tnDeque.push_back(root);
			//std::cout << root->val << std::endl;
			
			recursiveTraversal(root->left, tnDeque);
			recursiveTraversal(root->right, tnDeque);
		}
		void flatten(TreeNode *root)
		{
			deque<TreeNode *> tnDeque;
			recursiveTraversal(root, tnDeque);
			//std::cout << __LINE__ << std::endl;
			//对队列进行判断，以免后续访问迭代器出错
			if (tnDeque.empty())
			  return;
			for (deque<TreeNode *>::iterator iter = tnDeque.begin(); iter != tnDeque.end()-1; ++iter)
			{
				(*iter)->left = nullptr;
				(*iter)->right = *(iter + 1);
			}
		}
};

int main(int argc, char *argv[])
{
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	tn1.left = &tn2;
	tn1.right = &tn3;

	Solution so;
	so.flatten(&tn1);
	TreeNode *head = &tn1;
	while (head)
	{
		std::cout << head->val << " ";
		head = head->right;
	}
	std::cout << std::endl;
	return 0;
}
