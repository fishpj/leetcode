/*
 * Filename:	ValidPalindrome.cpp
 * Author:		fishpj
 * Date:		09/06/2014
 */

#include "leetCode.h"
#include <string>
using std::string;

class Solution
{
	public:
		bool isPalindrome(string s)
		{
			//为空串时也为palindrome
			if (s.empty())
			  return true;
			string str = "";
			//将字符串过滤，重新组成只含有数字和小写字母的字符串
			for (string::size_type ix = 0; ix != s.size(); ++ix)
			{
				if (isalpha(s[ix]))
				{
					str += tolower(s[ix]);
				}
				else if (isdigit(s[ix]))
				  str += s[ix];
				else
				  continue;
			}
			string::iterator beg = str.begin(), end = str.end()-1;
			while (beg < end)
			{
				if (*beg != *end)
				  return false;
				++beg;
				--end;
			}
			return true;
		}
};

int main(int argc, char *argv[])
{
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	string s3 = "";
	string s4 = "a.";
	Solution so;

	std::cout << so.isPalindrome(s1) << std::endl;
	std::cout << so.isPalindrome(s2) << std::endl;
	std::cout << so.isPalindrome(s3) << std::endl;
	std::cout << so.isPalindrome(s4) << std::endl;

	return 0;
}
