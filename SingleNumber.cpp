/*
 * Filename:	SingleNumber.cpp
 * Author:		fishpj
 * Date:		08/31/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int singleNumber(int A[], int n)
		{
			int iSingleNum = A[0];
			for (int i = 1; i < n; ++i)
			{
				iSingleNum ^= A[i];
			}
			return iSingleNum;
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	int A[] = {1, 2, 1, 2, 3};
	std::cout << so.singleNumber(A, sizeof(A)/sizeof(int)) << std::endl;
	return 0;
}
