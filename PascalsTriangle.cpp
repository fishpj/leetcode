/*
 * Filename:	PascalsTriangle.cpp
 * Author:		fishpj
 * Date:		09/10/2014
 */

#include "leetCode.h"
#include <vector>
using std::vector;

class Solution
{
	public:
		vector<vector<int> > generate(int numRows)
		{
			vector<vector<int> > result;
			if (!numRows)
			  return result;
			result.push_back(vector<int>());
			result[0].push_back(1);
			if (1 == numRows)
			  return result;
			for (int i = 1; i < numRows; ++i)
			{
				result.push_back(vector<int>());
				result[i].push_back(1);
				for (int j = 1; j < i; j++)
				{
					result[i].push_back(result[i-1][j-1] + result[i-1][j]);
				}
				result[i].push_back(1);
			}
			return result;
		}
		void printPascalTriangle(vector<vector<int> > &result)
		{
			for (vector<vector<int> >::iterator iter1 = result.begin(); iter1 != result.end(); ++iter1)
			{
				std::cout << "[";
				for (vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
				  std::cout << *iter2 << ",";
				std::cout << "]" << std::endl;
			}
			return ;
		}
};

int main(int argc, char *argv[])
{
	vector<vector<int> > result;
	Solution so;
	result = so.generate(5);
	so.printPascalTriangle(result);

	return 0;
}
