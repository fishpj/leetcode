/*
 * Filename:	SqrtX.cpp
 * Author:		fishpj
 * Date:		09/11/2014
 */

#include "leetCode.h"
#include <cassert>

class Solution
{
	public:
		int sqrt(int x)
		{
			if (x < 0)
			  assert(0);
			if (0 == x || 1 == x)
			  return x;
			int res;
			int l = 1, r = x, mid;
			while (l <= r)
			{
				mid = (l+r)/2;
				if (mid  == x/mid)
				{
					return mid;
				}
				else if (mid > x/mid)
				{
					r = mid-l;
				}
				else
				{
					l = mid+1;
					res = mid;
				}
			}
			return res;
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	std::cout << so.sqrt(4) << std::endl;
	std::cout << so.sqrt(2) << std::endl;
	return 0;
}
