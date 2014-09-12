/*************************************************************************
	> File Name: SearchInRotatedSortedArray.cpp
	> Author: fishpj
	> Mail: 
	> Created Time: 2014年09月13日 星期六 01时11分11秒
 ************************************************************************/

#include "leetCode.h"
#include<iostream>
using namespace std;

class Solution
{
    public:
    int search(int A[], int n, int target)
    {
        //先查找旋转位置
        int iPos = 0;
        while (iPos < n-1 && A[iPos] < A[iPos+1] )
            iPos++;
        if (iPos == n-1)
        {
            if (target >= A[0] && target <= A[n-1])
                return binarySearch(A, 0, n-1, target);
            else
                return -1;
        }
        else
        {
            if (target >= A[iPos+1] && target <= A[iPos])
            {
                if (target  A[0])
                    return binarySearch(A, 0, iPos, target);
                else
                    return binarySearch(A, iPos+1, n-1, target);
            }
            else
                return -1;
        }
    }
    private:
    int binarySearch(int A[], int iBeg, int iEnd, int target)
    {
        while (iBeg <= iEnd)
        {
            int iMid = (iBeg+iEnd)/2;
            if (target == A[iMid])
                return iMid;
            else if (target > A[iMid])
            {
                iBeg = iMid+1;
            }
            else
            {
                iEnd = iMid-1;
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    int A[] = {4, 5, 6, 7, 0, 1, 2};
    int B[] = {3, 1};
    Solution so;
    //std::cout << so.search(A, 7, -1) << std::endl;
    //std::cout << so.search(A, 7, 10) << std::endl;
    //std::cout << so.search(A, 7, 5) << std::endl;
    //std::cout << so.search(A, 7, 1) << std::endl;
    std::cout << so.search(B, 2, 3) << std::endl;
    return 0;
}
