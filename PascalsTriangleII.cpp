/*
 * Filename:	PascalTriangleII.cpp
 * Author:		fishpj
 * Date:		09/10/2014
 */

#include "leetCode.h"
#include <vector>
using std::vector;

class Solution
{
	public:
		vector<int> getRow(int rowIndex)
		{
			vector<int> result(rowIndex+1, 1);
			for (int i = 0; i <= rowIndex; ++i)
			  for (int j = i - 1; j >= 1; --j)
				result[j] = result[j-1] + result[j];
			return result;
		}
		void printResult(vector<int> &result)
		{
			vector<int>::iterator iter = result.begin();
			while (iter != result.end())
			  std::cout << *iter++ << " ";
			std::cout << std::endl;
			return;
		}
};

int main(int argc, char *argv[])
{
	Solution so;
	vector<int> result;
	result = so.getRow(3);
	so.printResult(result);
	result = so.getRow(4);
	so.printResult(result);
	result = so.getRow(5);
	so.printResult(result);
	return 0;
}
