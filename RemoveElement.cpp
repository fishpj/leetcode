/*
 * Filename:	RemoveElement.cpp
 * Author:		fishpj
 * Date:		09/07/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int removeElement(int A[], int n, int elem)
		{
			//从前往后找一个elem，从后往前找一个非elem，然后调换，直到i>j为止
			int i = 0, j = n - 1;
			while (i <= j)
			{
				int iTemp = 0;
				while (A[i] != elem && i < n)
				  ++i;
				while (A[j] == elem && j >= 0)
				  --j;
				if (i < j)
				{
					iTemp = A[i];
					A[i] = A[j];
					A[j] = iTemp;
				}
			}
			return j+1;
		}
};

int main(int argc, char *argv[])
{
	int A[] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
	Solution so;
	std::cout << so.removeElement(A, 12, 1) << std::endl;
	return 0;
}
