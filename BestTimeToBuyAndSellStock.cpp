/*
 * Filename:	BestTimeToBuyAndSellStock.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"
#include <vector>
#include <cmath>
using std::vector;
using std::max;
using std::min;

class Solution
{
	public:
		int maxProfit(vector<int> &prices)
		{
			if(prices.size() < 2)
			  return 0;
			int iMin = *(prices.begin()), iMaxProfit = 0;
			for (vector<int>::iterator iter = prices.begin()+1; iter != prices.end(); ++iter)
			{
				iMaxProfit = max(*iter-iMin, iMaxProfit);
				iMin = min(*iter, iMin);
			}
			return iMaxProfit;
		}
		/*//暴力破解
		int maxProfit(vector<int> &prices)
		{
		
			int iMaxProfit = 0;
			for (vector<int>::iterator iter1 = prices.begin(); iter1 != prices.end()-1; ++iter1)
			{
				for (vector<int>::iterator iter2 = iter1+1; iter2 != prices.end(); ++iter2)
				{
					iMaxProfit = (iMaxProfit > (*iter2 - *iter1) ? iMaxProfit:(*iter2 - *iter1));
				}
			}
			return iMaxProfit;
		}
		*/
};

int main(int argc, char *argv[])
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
