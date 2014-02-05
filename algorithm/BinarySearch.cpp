/*Binary Search*/
#include <iostream>
using namespace std;

int BSearch(int input[], int head, int tail, int num)
{
    if(head>tail)   return -1;
    int mid = (tail+head)/2;
    if(input[mid] == num)   return mid;
    else if(input[mid]>num)    return BSearch(input, head, mid-1, num);
    else return  BSearch(input, mid+1, tail, num);
}

int main()
{
    int input[5] = {3,4,7,8,9};
    cout<<BSearch(input, 0, 4, 3);
}
