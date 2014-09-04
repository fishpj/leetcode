/*
 * Filename:	AddBinary.cpp
 * Author:		fishpj
 * Date:		09/03/2014
 */

#include "leetCode.h"
#include <string>
using std::string;

class Solution
{
	public:
		string addBinary(string a, string b)
		{
			string::size_type sa = a.size();
			string::size_type sb = b.size();
			string result = sa > sb ? a:b;
			int overFlow = 0;
		
			for (string::size_type i = 0; i != result.size(); ++i)
			{
				char ca = i < sa ? a[sa-i-1] : '0';
				char cb = i < sb ? b[sb-i-1] : '0';
				int bit = (ca-'0') + (cb-'0') + overFlow;
				overFlow = bit/2;
				result[result.size()-i-1] = bit%2 + '0';
			}
			if (overFlow)
			result = '1' + result;
			return result;
		}
};

int main(int argc, char *argv[])
{
	string a = "1010";
	string b = "1111";
	Solution so;
	std::cout << so.addBinary(a, b) << std::endl;
}
