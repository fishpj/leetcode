/*
 * Filename:	SearchInsertPosition.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int searchInsert(int A[], int n ,int target)
		{
			//case1:直接查找
			if (target <= A[0])
			  return 0;
			else if (target >= A[n-1])
			  return n;
			for (int i = 1; i < n; ++i)
			{
				if (target > A[i-1] && target <= A[i])
				  return i;
			}
			//case2:二分查找
		}
};

int main(int argc, char *argv[])
{
	int A[] = {1, 3, 5, 6};
	Solution so;
	std::cout << so.searchInsert(A, 4, 5) << std::endl;
	std::cout << so.searchInsert(A, 4, 2) << std::endl;
	std::cout << so.searchInsert(A, 4, 7) << std::endl;
	std::cout << so.searchInsert(A, 4, 0) << std::endl;

	return 0;
}
