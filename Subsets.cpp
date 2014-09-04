/*
 * Filename:	Subsets.cpp
 * Author:		fishpj
 * Date:		09/04/2014
 */

#include "leetCode.h"
#include <vector>
#include <algorithm>
#include <set>
using std::vector;
using std::set;

class Solution
{
	public:
		void recursiveSubsets(vector<vector<int> > &result, set<int> &iset, vector<int> &S, int n)
		{
			if (n == S.size())
			{
				vector<int> ivec;
				for (set<int>::iterator iter = iset.begin(); iter != iset.end(); ++iter)
				  ivec.push_back(*iter);
				result.push_back(ivec);
				return;
			}
			iset.insert(S[n]);
			recursiveSubsets(result, iset, S, n+1);
			iset.erase(S[n]);
			recursiveSubsets(result, iset, S, n+1);
		}

		vector<vector<int> > subsets(vector<int> &S)
		{
			/*对vector<vector<int> > 中的元素逐个进行插入
			sort(S.begin(), S.end());
			vector<vector<int> > result;
			vector<int> ivec;
			int ivSize = S.size();
			int ivvSize = 0;
			//插入空集
			result.push_back(vector<int>{});
			for (vector<int>::size_type ix = 0; ix != ivSize; ++ix)
			{
				ivvSize = result.size();
				for (vector<vector<int> >::size_type i = 0; i != ivvSize; ++i)
				{
					ivec = result[i];
					ivec.push_back(S[ix]);
					result.push_back(ivec);
				}
			}
			return result;
			*/
			
			//case1:采用回溯递归调用完成。
			vector<vector<int> > result;
			set<int> iset;
			recursiveSubsets(result, iset, S, 0);
			return result;
		}
};

int main(int argc, char *argv[])
{
	vector<int> S;
	vector<vector<int> > result;
	S.push_back(3);
	S.push_back(2);
	S.push_back(1);

	Solution so;
	result = so.subsets(S);
	for (vector<vector<int> >::size_type i = 0; i != result.size(); ++i)
	{
		for (vector<int>::size_type j = 0; j != result[i].size(); ++j)
		{
			std::cout << result[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
