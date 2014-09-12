/*************************************************************************
	> File Name: ValidParentheses.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月13日 星期六 00时42分17秒
 ************************************************************************/

#include "leetCode.h"
#include<iostream>
#include <stack>

using namespace std;

class Solution
{
    public:
    bool isValid(string s)
    {
        stack<char> cStack;
        for (string::size_type i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                cStack.push(s[i]);
            else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
            {
                if (cStack.empty())
                    return false;
                char cTmp = cStack.top();
                switch(cTmp)
                {
                    case '(':
                           {
                               if (s[i] == ')')
                               {
                                   cStack.pop();
                                   break;
                               }
                               else
                                    return false;
                           }
                    case '[':
                           {
                               if (s[i] == ']')
                               {
                                   cStack.pop();
                                   break;
                               }
                               else
                                    return false;
                           }
                    case '{':
                           {
                               if (s[i] == '}')
                                {
                                    cStack.pop();
                                    break;
                                }
                                else
                                    return false;
                           }
                }    
            }else
                return false;
        }
        if (!cStack.empty())
            return false;
        return true;
    }
};


int main(int argc, char *argv[])
{
    string s1 = "()[]{}";
    string s2 = "{{{}}}";
    string s3 = "()))";

    Solution so;
    cout << so.isValid(s1) << endl;
    cout << so.isValid(s2) << endl;
    cout << so.isValid(s3) << endl;
    return 0;
}
