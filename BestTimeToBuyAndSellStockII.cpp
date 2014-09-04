/*
 * Filename:	BestTimeToBuyAndSellStockII.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"
#include <vector>
using std::vector;

class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			if (prices.size() < 2)
			  return 0;

			int iMaxProfit = 0;
			for (vector<int>::iterator iter = prices.begin()+1; iter != prices.end(); ++iter)
			{
				if (*iter > *(iter-1))
				  iMaxProfit += (*iter - *(iter-1));
			}
			return iMaxProfit;
		}
};

int main(int, char *argv[])
{
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(2);
	prices.push_back(3);
	prices.push_back(10);

	Solution so;
	std::cout << so.maxProfit(prices) << std::endl;
	return 0;
}
