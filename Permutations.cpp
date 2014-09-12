/*************************************************************************
	> File Name: Permutations.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月12日 星期五 09时45分04秒
 ************************************************************************/

#include "leetCode.h"
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
    void recursivePermute(vector<vector<int> > &result, vector<int> &num, int n)
    {
        if (n == num.size())
        {
            result.push_back(num);
        }
        else
        {
            for (int i = n; i < num.size(); ++i)
            {
                swap(num[i], num[n]);
                recursivePermute(result, num, n+1);
                swap(num[i], num[n]);
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        recursivePermute(result, num, 0);
        return result;
    }
    void printCheck(vector<vector<int> > &result)
    {
        for (vector<vector<int> >::iterator iter1 = result.begin(); iter1 != result.end(); ++iter1)
        {
            for (vector<int>::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2)
                std::cout << *iter2 << " ";
            std::cout << std::endl;
        }
        return;
    }
};

int main(int argc, char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    vector<vector<int> > result;
    Solution so;
    result = so.permute(num);
    so.printCheck(result);
    return 0;
}
