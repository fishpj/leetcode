/*
 * Filename:	ClimbingStairs.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"

class Solution
{
	public:
		int climbStairs(int n)
		{
			/*递归出现TLB
			//递归求解
			if (n == 1 || n == 0)
			  return 1;
			else
			  return climbStairs(n-1) + climbStairs(n-2);
			*/
			if (n <= 1)
			  return n;
			
			int *a = new int[n+1];
			int iClimbStairs = 0;
			a[0] = 1;
			a[1] = 1;
			for (int i = 2; i <= n; i++)
				a[i] = a[i-1] + a[i-2];
			iClimbStairs = a[n];
			delete []a;
			return iClimbStairs;
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	std::cout << so.climbStairs(1) << std::endl;
	std::cout << so.climbStairs(2) << std::endl;
	std::cout << so.climbStairs(3) << std::endl;
	std::cout << so.climbStairs(4) << std::endl;
	std::cout << so.climbStairs(5) << std::endl;
	std::cout << so.climbStairs(6) << std::endl;

	return 0;
}
