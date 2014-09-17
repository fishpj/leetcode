/*************************************************************************
	> File Name: StringToInteger.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月13日 星期六 10时35分21秒
 ************************************************************************/

#include "leetCode.h"
#include<iostream>
#include <climits>
#include <string>
using namespace std;

class Solution
{
    public:
    int atoi(const char *str)
    {
        //处理空串
        if (NULL == str)
            return 0;

        //过滤开头的空格
        while (isspace(*str))
            ++str;

        //处理正负
        int sign = 1;
        if ('+' == *str || '-' == *str)
        {
            if ('-' == *str)
                sign = -1;
            ++str;
        }
        unsigned int result;

        while (isdigit(*str))
        {
            //处理溢出
            int c = *str -'0';
            if (sign > 0 && (result > INT_MAX/10 || (result == INT_MAX / 10 && c > INT_MAX % 10)))
            {
                result = INT_MAX;
                break;
            }
            else if (sign < 0 && (result > (unsigned)INT_MIN/10 || (result == (unsigned)INT_MIN / 10 && c > (unsigned)INT_MIN % 10)))
            {
                result = INT_MIN;
                break;
            }
            result = result*10 + c;
            ++str;
        }
        /*可以存在非数字字符，这个时候只取前面已判断字段
        if ('\0' == *str)
            return 0;
        */
        return sign == 1 ? result : -result;
    }
};

int main(int argc, char *argv[])
{
    //const int TEST = (int)((unsigned)~0);
    //const int MAX_INT = (int)((unsigned)~0 >> 1);
    //const int MIN_INT = -(int)((unsigned)~0 >> 1) - 1;


    //cout << ((unsigned)~0 >> 1) << endl;
    //cout << INT_MAX << endl;
    //cout << INT_MIN << endl;
    //cout << (unsigned)INT_MIN << endl;
    string s1 = ("222222222222222");
    string s2 = ("-111111111111111");
    Solution so;
    cout << so.atoi(s1.c_str()) << endl;
    cout << so.atoi(s2.c_str()) << endl;

    return 0;
}

