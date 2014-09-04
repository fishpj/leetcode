/*
 * Filename:	BinaryTreeInorderTraversal.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"
#include <vector>
#include <stack>
using std::vector;
using std::stack;

class TreeNode
{
public:
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL)
	{}
};

class Solution
{
	public:
		vector<int> inorderTraversal(TreeNode *root)
		{
			vector<int> ivec;
			if (root == NULL)
			  return ivec;
			stack<TreeNode *> tnStack;
			struct TreeNode* tnTop = root;

			while (tnTop != NULL || !tnStack.empty())
			{
				while (tnTop != NULL)
				{
					tnStack.push(tnTop);
					tnTop = tnTop->left;
				}

				if (!tnStack.empty())
				{
					tnTop = tnStack.top();
					ivec.push_back(tnTop->val);
					tnStack.pop();
					tnTop = tnTop->right;
					while (tnTop)
					{
						tnStack.push(tnTop);
						tnTop = tnTop->left;
					}
				}
			}

			/*
			while (!tnStack.empty() || tnTop != NULL)
			{
				if (NULL == tnTop)
				  return ivec;
				while (tnTop->left)  //遍历左孩子
				{
					//std::cout << tnStack.top()->val << std::endl;
					tnStack.push(tnTop->left);
					tnTop = tnTop->left;
				}
				if(!tnStack.empty())
				{
					tnTop = tnStack.top();
					ivec.push_back(tnTop->val);
					tnStack.pop();
					tnTop = tnTop->right;
					while (tnTop)
					{
						tnStack.push(tnTop);
						tnTop = tnTop->left;
						
					}
				}
			}*/
				/*
				if (tnTop->left)
				  tnStack.push(tnTop->left);
				else
				{
					//tnTop = tnStack.top();
					ivec.push_back(tnTop->val);
					if (tnTop->right)
					  tnTop = tnTop->right;
					else
					  tnTop = NULL;
					tnStack.pop();
					if (tnTop)
						tnStack.push(tnTop);
				}*/
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
	tn2.left = &tn3;
	tn3.left = &tn4;

	TreeNode tn5(5);
	TreeNode tn6(6);
	tn1.right = &tn5;
	tn5.left = &tn6;
	Solution so;
	std::cout << (so.inorderTraversal(&tn1))[0] << std::endl;
	std::cout << (so.inorderTraversal(&tn1))[1] << std::endl;
	std::cout << (so.inorderTraversal(&tn1))[2] << std::endl;
	std::cout << (so.inorderTraversal(&tn1))[3] << std::endl;
	std::cout << (so.inorderTraversal(&tn1))[4] << std::endl;
	std::cout << (so.inorderTraversal(&tn1))[5] << std::endl;
	return 0;
}


