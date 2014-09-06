/*
 * Filename:	SubsetsII.cpp
 * Author:		fishpj
 * Date:		09/05/2014
 */

#include "leetCode.h"
#include <algorithm>
#include <vector>
#include <set>
using std::set;
using std::vector;

class Solution
{
	public:
		/*
		bool myFunction(vector<int> &v1, vector<int> &v2)
		{
			if (v1.size() == v2.size())
			{
				if (v1.empty())
				  return true;
				for (int i = 0; i != v1.size(); ++i)
				{
					if (v1[i] != v2[i])
						return false;
				}
				return true;
			}
			return false;
		}
		*/
		void recursiveSubsets(vector<vector<int> > &result, vector<int> &v, vector<int> &S, int n)
		{
			if (n == S.size())
			{
				vector<int> ivec;
				for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
				  ivec.push_back(*iter);
				result.push_back(ivec);
				return ;
			}
			v.push_back(S[n]);
			recursiveSubsets(result, v, S, n+1);
			v.pop_back();
			recursiveSubsets(result, v, S, n+1);
		}
		vector<vector<int> > subsetsWithDup(vector<int> &S)
		{
			vector<vector<int> > result;
			sort(S.begin(), S.end());
			//result.push_back(vector<int>{});
			vector<int> ivec;

			recursiveSubsets(result, ivec, S, 0);
			//为消除result出现重复但不相邻向量，需再做一次排序
			sort(result.begin(), result.end());
			//unique操作去掉重复子集后重新设置result大小
			vector<vector<int> >::iterator it = std::unique(result.begin(), result.end());
			result.resize(std::distance(result.begin(), it));
			return result;
		}
};

int main(int argc, char *argv[])
{
	vector<int> ivec;
	ivec.push_back(1);
	ivec.push_back(1);
	ivec.push_back(2);
	ivec.push_back(2);
	vector<vector<int> > vtest;
	Solution so;
	vtest = so.subsetsWithDup(ivec);

	std::cout << vtest.size() << std::endl;
	for (vector<vector<int> >::iterator iter1 = vtest.begin(); iter1 != vtest.end(); ++iter1)
	{
		for (vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
					std::cout << *iter2 << " ";
		std::cout << std::endl;
	}
	return 0;
}
