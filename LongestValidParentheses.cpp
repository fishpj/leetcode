/*
 * Filename:	LongestValidParentheses.cpp
 * Author:		fishpj
 * Date:		09/04/2014
 */

#include "leetCode.h"
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::stack;
using std::string;

class Solution
{
	public:
		int longestValidParentheses(string s)
		{
			vector<int> stack;
			int maxLen = 0;
			for (int i =0; i < s.size(); ++i)
			{
				if (s[i] == '(')
				  stack.push_back(i);
				else
				{
					if (!stack.empty() && s[stack.back()] == '(')
					{
						stack.pop_back();
						int lastPos = -1;
						if (!stack.empty())
						  lastPos = stack.back();
						int curLen = i -lastPos;
						maxLen = (maxLen < curLen) ? curLen:maxLen;
					}
					else
					  stack.push_back(i);
				}
			}
			return maxLen;
			/*
			int iMax = 0;
			stack<int> iStack;	

			//增加i等于size用于判断最后一段位置
			for (int i = 0; i != iStack.size(); ++i)
			{
				if ('(' == s[i])
				  iStack.push(i);
				else
				{
					if (!iStack.empty() && '(' == s[iStack.top()])
					{
						iStack.pop();
						int lastPos = -1;
						if (!iStack.empty())
						  lastPos = iStack.top();
						int iLength = i - lastPos;
						iMax = iMax > iLength ? iMax:iLength;
					}
					else
					  iStack.push(i);
				}
			}
			*/
				/*
				if (cStack.empty() || '(' == s[i])
				{
					if ('(' == s[i])
					{
						cStack.push(s[i]);
						++i;
					}
					else
					{
						iMax = iMax > iLength ? iMax: iLength;
						iLength = 0;
						++i;
					}
				}
				else if ('(' == cStack.top() && ')' == s[i])
				{
					iLength += 2;
					cStack.pop();
					++i;
				}
			}
			return iMax;*/
		}
};

int main(int argc, char *argv[])
{
	string s1 = "()()";
	string s2 = ")()())";
	string s3 = "(()()()()";

	Solution so;
	std::cout << so.longestValidParentheses(s1) << std::endl;
	std::cout << so.longestValidParentheses(s2) << std::endl;
	std::cout << so.longestValidParentheses(s3) << std::endl;

	return 0;
}
