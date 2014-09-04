/*
 * Filename:	BinaryTreePostorderTraversal.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class Solution
{
	public:
		vector<int> postorderTraversal(TreeNode *root)
		{
			vector<int> result;
			stack<TreeNode *> tnStack;
			if ( NULL == root)
			  return result;
			tnStack.push(root);

			TreeNode *prev = NULL;
			while (!tnStack.empty())
			{
				TreeNode *cur = tnStack.top();

				//分三种情况退栈，1。右孩子存在，先pop节点为当前栈顶右孩子。
				//				  2。右孩子不存在，先pop节点为当前节点左孩子
				//				  3。左右孩子都不存在
				if (cur->right && cur->right == prev || !cur->right && cur->left == prev || !cur->left && !cur->right)
				{
					tnStack.pop();
					result.push_back(cur->val);
					std::cout << cur->val << std::endl;
					prev = cur;
					continue;
				}

				if (cur->right)
				  tnStack.push(cur->right);
				if (cur->left)
				  tnStack.push(cur->left);
			}
			return result;
		}
};

int main(int argc, char *argv[])
{
	TreeNode ln1(1);
	TreeNode ln2(2);
	TreeNode ln3(3);
	TreeNode ln4(4);
	TreeNode ln5(5);
	TreeNode ln6(6);
	TreeNode ln7(7);

	ln1.left = &ln2, ln1.right = &ln3;
	//ln2.left = &ln4, ln2.right = &ln5;
	ln3.left = &ln6, ln3.right = &ln7;

	vector<int> result;

	Solution so;
	result = so.postorderTraversal(&ln1);

	for (vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter)
	  std::cout << *iter << " ";
	std::cout << std::endl;
	return 0;
}
