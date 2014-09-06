/*
 * Filename:	Pow.cpp
 * Author:		fishpj
 * Date:		09/07/2014
 */

#include "leetCode.h"
#include <cmath>
using std::abs;

class Solution
{
	public:
		double pow(double x, int n)
		{
			//采用递归分化计算
			if (1 == x || 0 == n)
			  return 1;
			if (-1 == x)
			{
				if (n%2)
				  return -1;
				else
				  return 1;
			}
			if ( n < 0)
			  return (1/pow(x, -n));
			if (1 == n%2)
			  return (pow(x*x, n/2)*x);
			else
			  return (pow(x*x, n/2));
			/*直接这样左出现TLB错误
			double result = 1;
			//需考虑n的正负
			if (n >= 0)
			{
				while (n--)
				  result *=x;
			}
			else
			{
				n = abs(n);
				while (n--)
				  result *= x;
				result = 1/result;
			}
			return result;
			*/
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	std::cout << so.pow(10, 3) << std::endl;
	std::cout << so.pow(2, 10) << std::endl;
	std::cout << so.pow(34.00515, -3) << std::endl;
	return 0;
}
