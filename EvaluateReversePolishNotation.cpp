/*
 * Filename:	EvaluateReversePolishNotation.cpp
 * Author:		fishpj
 * Date:		09/02/2014
 */

#include "leetCode.h"
#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::stack;
using std::string;
using std::stoi;

class Solution
{
	public:
		int myOperation(int i, int j, char c)
		{
			switch(c)
			{
				case '+':
					return i+j;
				case '-':
					return j-j;
				case '*':
					return i*j;
				case '/':
					return i/j;
				default:
					return 0;
			}
		}
		//逆波兰式实际上是对二叉树后序遍历的结果,这里采用栈实现
		int evalRPN(vector<string> &tokens)
		{
			if (tokens.empty())
			  return 0;
			stack<int> iStack;

			iStack.push(stoi(tokens[0]));
			for (vector<string>::iterator iter = tokens.begin()+1; iter != tokens.end(); ++iter)
			{
				if (!isdigit((*iter)[0]) && (*iter).size()==1)
				{
					int i = iStack.top();
					iStack.pop();
					int j = iStack.top();
					iStack.pop();
					iStack.push(myOperation(j, i, (*iter)[0]));
				}
				else
				  iStack.push(stoi(*iter));
			}
			return iStack.top();
		}
};

int main(int argc, char *argv[])
{
	vector<string> sVec;
	sVec.push_back("2");
	sVec.push_back("1");
	sVec.push_back("+");
	sVec.push_back("3");
	sVec.push_back("*");
	Solution so;
	std::cout << so.evalRPN(sVec) << std::endl;
	sVec.clear();
	sVec.push_back("4");
	sVec.push_back("13");
	sVec.push_back("5");
	sVec.push_back("/");
	sVec.push_back("+");
	std::cout << so.evalRPN(sVec) << std::endl;
	sVec.clear();
	sVec.push_back("-1");
	sVec.push_back("1");
	sVec.push_back("*");
	sVec.push_back("-1");
	sVec.push_back("+");
	std::cout << so.evalRPN(sVec) << std::endl;
	return 0;
}
