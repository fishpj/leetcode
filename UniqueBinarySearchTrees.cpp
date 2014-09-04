/*
 * Filename:	UniqueBinarySearchTrees.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		//采用递归式构造
		int numTrees(int n)
		{
			if ( n <= 1)
			  return 1;
			else
			{
				int iNumTrees = 0;
				for (int i = 1; i <= n; ++i)
				{
					iNumTrees += numTrees(n-i)*numTrees(i-1);
				}
				return iNumTrees;
			}
			
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	std::cout << so.numTrees(4) << std::endl;

	return 0;
}
