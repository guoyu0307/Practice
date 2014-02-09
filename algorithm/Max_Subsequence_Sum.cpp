#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Max3(int a, int b, int c)
{
    if(a>b)
    {
        if(a>c) return a;
        else    return c;
    }
    else
    {
        if(b>c) return b;
        else    return c;
    }
}

int MaxSubSequence(int a[], int left, int right)
{
    if(left == right)   
	{
		if(a[left] < 0)	return 0;
		else	return a[left];
	}

    int center_index = (left+right)/2;
    int Max_Sum_left = MaxSubSequence(a, left, center_index);
    int Max_Sum_right = MaxSubSequence(a,center_index+1,right);

    int Sum_left = 0;
    int Sum_right = 0;

    int part_sum_left = 0;
    for(int i=center_index;i>=left;i--)
    {
        part_sum_left += a[i];
        if(part_sum_left > Sum_left)   Sum_left = part_sum_left;
    }

    int part_sum_right = 0;
    for(int j = center_index+1;j<=right;j++)
    {
        part_sum_right += a[j];
        if(part_sum_right > Sum_right) Sum_right = part_sum_right;
    }

    return Max3(Max_Sum_left, Max_Sum_right, Sum_left + Sum_right);
}



int main()
{
    int a[8] = {4,-3,5,-2,-1,2,6,-2};
    cout<<MaxSubSequence(a, 0, 7);
}
