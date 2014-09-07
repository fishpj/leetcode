/*
 * Filename:	RemoveDuplicatesFromSortedArrayII.cpp
 * Author:		fishpj
 * Date:		09/08/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int removeDuplicates(int A[], int n)
		{
			if (!n)
			  return 0;
			int i = 0;
			int iCount = 1;
			for (int j = 1; j < n; ++j)
			{
				if (A[j] != A[i])
				{
				  A[++i] = A[j];
				  iCount = 1;
				}
				else if(1 == iCount)
				{
					A[++i] = A[j];
					iCount = 2;
				}
			}
			return i+1;
		}
};

int main(int argc, char *argv[])
{
	int A[] = {1, 1, 1, 2, 2, 3};
	Solution so;
	int iLength = 0;
	iLength = so.removeDuplicates(A, sizeof(A)/sizeof(int));
	for (int i = 0; i < iLength; ++i)
	  std::cout << A[i] << " ";
	std::cout << std::endl;
	return 0;
}
