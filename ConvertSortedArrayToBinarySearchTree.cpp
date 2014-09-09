/*
 * Filename:	ConvertSortedArrayToBinarySearchTree.cpp
 * Author:		fishpj
 * Date:		09/09/2014
 */

#include "leetCode.h"
#include <cassert>
#include <vector>
using std::vector;

class Solution
{
	public:
		/*
		//不提供其他函数，直接调用自己递归完成,涉及大量向量拷贝，容易出现MLE
		//本题测试未出现MLE。
		TreeNode *sortedArrayToBST(vector<int> &num)
		{
			if (num.empty())
			  return nullptr;
			if (1 == num.size())
			{
				TreeNode *root = new TreeNode(num[0]);
				assert(root);
				return root;
			}
			
			TreeNode *root = new TreeNode(num[num.size()/2]);
			std::cout << "root->val = " << root->val << std::endl;
			assert(root);
			vector<int> ivecLeft(num.begin(), num.begin()+num.size()/2);
			vector<int> ivecRight(num.begin()+num.size()/2+1, num.end()); 
			root->left = sortedArrayToBST(ivecLeft);
			root->right = sortedArrayToBST(ivecRight);
			
			return root;
		}
		*/
		//通过迭代器传递避免向量拷贝导致MLE
		TreeNode *recursiveSortedArrayToBST(vector<int>::iterator beg, vector<int>::iterator end)
		{
			if (0 == end - beg)
			  return nullptr;
			if (1 == end - beg)
			{
				TreeNode *root = new TreeNode(*beg);
				assert(root);
				return root;
			}
			TreeNode *root = new TreeNode(*(beg+(end-beg)/2));
			assert(root);
			root->left = recursiveSortedArrayToBST(beg, beg+(end-beg)/2);
			root->right = recursiveSortedArrayToBST(beg+(end-beg)/2+1, end);
			return root;
			
		}
		TreeNode *sortedArrayToBST(vector<int> &num)
		{
			return recursiveSortedArrayToBST(num.begin(), num.end());
		}
		//中序遍历二叉排序树得到的序列即为排序好的数组，检查二叉排序树创建是否正确
		void inorderTraversal(TreeNode *root)
		{
			if (root)
			{
				inorderTraversal(root->left);
				std::cout << root->val << " ";
				inorderTraversal(root->right);
			}
			return;
		}
};

int main(int argc, char *argv[])
{
	int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> ivec(A, A+sizeof(A)/sizeof(int));
	Solution so;
	TreeNode *root = nullptr;
	root = so.sortedArrayToBST(ivec);
	so.inorderTraversal(root);
	std::cout << std::endl;
	return 0;
}
