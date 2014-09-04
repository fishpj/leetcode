/*
 * Filename:	SingleNumberII.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int singleNumber(int A[], int n)
		{
			//参考实现
			int ones = 0, twos = 0;
			for (int i = 0; i < n; ++i)
			{
				ones = (ones ^ A[i]) & ~twos;
				twos = (twos ^ A[i]) & ~ ones;
			}
			return ones;
		}
};

int main(int argc, char *argv[])
{
	int A[] = {1, 1, 1, 3, 3, 3, 4, 4, 4, 5};

	Solution so;

	std::cout << so.singleNumber(A, sizeof(A)/sizeof(int)) << std::endl;
	return 0;
}
