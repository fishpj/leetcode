/*
 * Filename:	ReverseInteger.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */
#include "leetCode.h"
class Solution
{
	public:
		int reverse(int x)
		{
			int y=0, z =0;
			if (x >= 0)
			  z = x;
			else
			  z = -x;
			while (z/10)
			{	
				y = (y + z%10)*10;
				z = z/10;
			}
			return (x > 0 ? (y+z):-(y+z));
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	std::cout << so.reverse(123456) << std::endl;
	std::cout << so.reverse(-12345) << std::endl;
	return 0;
}
