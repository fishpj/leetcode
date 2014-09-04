/*
 * Filename:	MergeSortedArray.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		void merge(int A[], int m, int B[], int n)
		{
			int i = m, j = n, k = m + n;
			while (i > 0 && j > 0)
			{
				if (A[i-1] > B[j-1])
				  A[--k] = A[--i];
				else
				  A[--k] = B[--j];
			}
			//若i不等于零，说明已经将全部B数组拷贝到A
			//while (i != 0)
			  //A[--k] = A[--i];
			while (j != 0)
			  A[--k] = B[--j];
			/*增加移位操作出现TLE
			if (0 == m)
			{
				for (int i = 0; i < n; ++i)
				  A[i] = B[i];
				return;
			}
			//将数组后移n个单位
			for(int i = m-1; i >= 0; --i)
			{
				A[n+i] = A[i];
			}
			int i = 0, j = 0, k = 0;
			while (i < m+n)
			{

				if ((A[n+j] > B[k] && k < n) || j == m)
				{
					A[i] = B[k];
					++i;
					++k;
				}
				else if (j < m)
				{
					A[i] = A[n+j];
					++i;
					++j;
				}
			}*/
		}
};

int main(int argc, char *argv[])
{
	int A[10] = {1};
	int B[] = {2};

	for (size_t i = 0; i < 10; ++i)
	  std::cout << A[i] << " ";
	std::cout << std::endl;
	Solution so;
	so.merge(A, 1, B, 1);

	for (size_t i = 0; i < 10; ++i)
	  std::cout << A[i] << " ";
	std::cout << std::endl;

	return 0;
}
