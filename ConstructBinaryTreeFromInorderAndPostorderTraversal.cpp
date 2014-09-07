/*
 * Filename:	ConstructBinaryTreeFromInorderAndPostorderTraversal.cpp
 * Author:		fishpj
 * Date:		09/07/2014
 */

#include "leetCode.h"
#include <vector>
#include <cassert>
#include <algorithm>
using std::vector;

class Solution
{
	public:
		typedef vector<int>::iterator iiter;
		//查找到划分的节点位置
		vector<int>::iterator findMiddle(vector<int> &inorder, vector<int> &postorder)
		{
			vector<int>::iterator itMid = inorder.begin();
			int iRoot = postorder.back();
			while (*itMid != iRoot)
			  itMid++;
			return itMid;
		}
		TreeNode *recursiveBuildTree(iiter inBeg, iiter inEnd, iiter postBeg, iiter postEnd)
		{
			if (inBeg == inEnd)
			  return nullptr;
			if (1 == (inEnd-inBeg))
			{
				TreeNode *root = new TreeNode(*inBeg);
				assert(root);
				return root;
			}
			TreeNode *root = new TreeNode(*(postEnd-1));
			assert(root);
			iiter itMid = find(inBeg, inEnd, *(postEnd-1));
			root->left = recursiveBuildTree(inBeg, itMid, postBeg, postBeg+(itMid-inBeg));
			root->right = recursiveBuildTree(itMid+1, inEnd, postBeg+(itMid-inBeg), postEnd-1);
			return root;
		}
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
		{
			return recursiveBuildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
		}
		/*
		//采用递归寻找各棵树的根(该方法在递归时涉及到大量的响亮拷贝，测试时出现MLE)
		TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
		{
			//中序遍历结果为0
			if (inorder.empty())
			  return nullptr;
			//只有一个元素
			if (1 == inorder.size())
			{
				TreeNode *root = new TreeNode(inorder[0]);
				assert(root);
				return root;
			}
			TreeNode *root = new TreeNode(postorder.back());
			std::cout << "root->val = " << root->val << std::endl;
			//std::cout << __LINE__ << std::endl;
			assert(root);
			vector<int>::iterator itMid = findMiddle(inorder, postorder);
			//vector<int>::iterator itMid = find(inorder.begin(), inorder.end(), postorder.back());
			vector<int> inLeft(inorder.begin(), itMid), inRight(itMid+1, inorder.end());
			vector<int> postLeft(postorder.begin(), postorder.begin()+inLeft.size());
			vector<int> postRight(postorder.begin()+inLeft.size(), postorder.end()-1);
			//用于打印测试前后段的分块正确性
			//for (vector<int>::iterator it = inLeft.begin(); it != inLeft.end(); ++it)
			//	std::cout << *it << " ";
			//std::cout << std::endl;
			//for (vector<int>::iterator it = postLeft.begin(); it != postLeft.end(); ++it)
			//	std::cout << *it << " ";
			//std::cout << std::endl;
			//for (vector<int>::iterator it = inRight.begin(); it != inRight.end(); ++it)
			//	std::cout << *it << " ";
			//std::cout << std::endl;
			//for (vector<int>::iterator it = postRight.begin(); it != postRight.end(); ++it)
			//	std::cout << *it << " ";
			//std::cout << std::endl;
				root->left = buildTree(inLeft, postLeft);
				root->right = buildTree(inRight, postRight);
				return root;
			}
		}*/
		//增加先序遍历以测试构造的二叉树
		void preorderTraversal(TreeNode *root)
		{
			if (nullptr == root)
				return ;
			std::cout << root->val << " ";
			preorderTraversal(root->left);
			preorderTraversal(root->right);
			return ;
		}
};

int main(int argc, char *argv[])
{
	int A[] = {3, 2, 4, 1, 7, 6, 8, 5};
	int B[] = {3, 4, 2, 7, 8, 6, 5, 1};
	//int A[] = {2, 1};
	//int B[] = {2, 1};
	vector<int> inorder(A, A + sizeof(A)/sizeof(int));
	vector<int> postorder(B, B + sizeof(B)/sizeof(int));

	TreeNode *root = nullptr;
	Solution so;
	root = so.buildTree(inorder, postorder);
	//std::cout << __LINE__ << std::endl;
	so.preorderTraversal(root);
	std::cout << std::endl;
	return 0;
}
