/*
 * Filename:	BinaryTreeLevelOrderTraversal.cpp
 * Authro:		fishpj
 * Date:		09/09/2014
 */

#include "leetCode.h"
#include <vector>
using std::vector;

class Solution
{
	public:
		//case1:利用BFS递归完成
		void BFS(TreeNode *root, int iLevel, vector<vector<int> > &result)
		{
			if (!root)
			  return ;
			if (iLevel+1 > result.size())
			  result.push_back(vector<int>());
			BFS(root->left, iLevel+1, result);
			BFS(root->right, iLevel+1, result);
		}
		vector<vector<int> > levelOrder(TreeNode *root)
		{
			vector<vector<int> > result;
			BFS(root, 0, result);
			return result;
		}
};

int main(int argc, char *argv[])
{
	TreeNode tn1(1);
	TreeNode tn2(2);
	TreeNode tn3(3);
	TreeNode tn4(4);
	TreeNode tn5(5);
	TreeNode tn6(6);
	TreeNode tn7(7);
	TreeNode tn8(8);
	tn1.left = &tn2, tn1.right = &tn3;
	tn2.left = &tn4, tn2.right = &tn5;
	tn3.left = &tn6, tn3.right = &tn7;
	vector<vector<int> > result;
	Solution so;
	result = so.levelOrder(&tn1);

	return 0;
}
