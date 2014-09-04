/*
 * Filename:	LengthOfLastWord.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"
#include <string>
using std::string;

class Solution
{
	public:
		int lengthOfLastWord(const char *s)
		{
			//利用string库函数处理
			string str(s);
			int size = str.size();
			int length = 0;

			while (size >= 0)
			{
				if (isalpha(str[size-1]))
				{
					length++;
					size--;
				}
				else
				{
					if (length != 0)
					  return length;
					size--;
				}
			}
			return 0;
		}
};

int main(int argc, char *argv[])
{
	char *s = "a";
	Solution so;
	std::cout << so.lengthOfLastWord(s) << std::endl;

	return 0;
}
