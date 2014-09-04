/*
 * Filename:	ReverseWordsInAString.cpp
 * Author:		fishpj
 * Date:		09/01/2014
 */

#include "leetCode.h"
#include <vector>
#include <string>
#include <cctype>
using std::vector;
using std::string;

class Solution
{
	public:
		void reverseWords(string &s)
		{
			//采用string库函数操作
			std::vector<std::string> svec;
			/*
			std::string pattern = " ";
			std::string::size_type pos;
			//将字符串分割为一个个单词存储在vector中
			//扩招字符串以方便切割操作
			
			s += pattern;
			std::string::size_type size = s.size();
			for (string::size_type ix = 0; ix != size; ++ix)
			{
				pos = s.find(pattern, ix);
				if(pos < size)
				{
					std::string str = s.substr(ix, pos-ix);
					svec.push_back(str);
					ix = pos+pattern.size()-1;
				}
			}
			*/
			//重新切割字符串以适应特殊情况
			//从头开始遍历整个字符串，找到每个单词的字符开头和结束位置
			std::string::size_type beg = 0, end = 0;
			for (std::string::size_type ix = 0; ix < s.size(); ++ix)
			{
				while (isspace(s[ix]) && ix < s.size())
				  ++ix;
				beg = ix;
				while (!isspace(s[ix]) && ix < s.size())
				  ++ix;
				end = ix;
				if (end > beg)
				{
					std::string str = s.substr(beg, end-beg);
					//std::cout << str << std::endl;
					svec.push_back(str);
				}
			}
			//针对string全为空格时做处理
			if (svec.empty())
			{
				s.clear();
				return;
			}
			//清空原字符串，然后逆序插入单词
			s.clear();
			for (std::vector<std::string>::iterator iter = svec.end() - 1; iter >= svec.begin(); --iter)
			{
				s += *iter;
				if (iter != svec.begin())
					s += " ";
			}
		}
};

int main(int argc, char *argv[])
{
	string s = " 1";
	std::cout << s << std::endl;
	Solution so;
	so.reverseWords(s);
	std::cout << s << std::endl;
}
