#include <iostream>

using namespace std;

template<typename Type>
void insertion_sort(Type data[], int length)
{
    Type temp = 0;
    int index = 0;

    for(int i=1;i<length;i++)
    {
        temp = data[i];
        index = i-1;
        while((index>=0) && (data[index]>temp))
        {
            data[index+1] = data[index];
            index--;
        }
        data[index+1] = temp;
    }
}

template<typename Type>
void selection_sort(Type data[], int length)
{
    int index = 0;

    for(int i=0;i<length;i++)
    {
        index = i;
        for(int j=i+1;j<length;j++)
        {
            if(data[j]<data[index])     index = j;
        }

        Type temp = data[index];
        data[index] = data[i];
        data[i] = temp;
    }
}

void shell_sort(int A[], int n)
{
    for(int gap = n/2;gap>=1;gap /= 2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp = A[i];
            int j = i;
            for(;(j>=gap) && (temp<A[j-gap]);j -= gap)
            {
                A[j] = A[j-gap];
            }
            A[j] = temp;
        }
    }
}

namespace HeapSort
{
    void Heap_down(int A[], int index, int n)
    {
        int temp = A[index];
        int child = index*2+1;
        while(child < n)
        {
            if((child < n-1) && (A[child] < A[child+1]))
            {
                child ++;
            }

            if(A[child] > temp)
            {
                A[index] = A[child];
                index = child;
                child = index*2+1;
            }
            else    break;
        }
        A[index] = temp;
    }

    void bulidHeap(int A[], int n)
    {
        for(int i=n/2;i>=0;i--)
        {
            Heap_down(A,i,n);
        }
    }

    void Heap_sort(int A[], int n)
    {
        for(int i=n-1;i>0;i--)
        {
            swap(A[0], A[i]);
            Heap_down(A, 0, i);
        }
    }
}

namespace MergeSort
{
    void s_merge(int A[], int temp[], int start, int middle, int last)
    {
        int index = start;
        int left_start = start;
        int left_end = middle;
        int right_start = middle + 1;
        int right_end = last;

        while((left_start<=left_end) && (right_start <= right_end))
        {
            if(A[left_start] < A[right_start])
            {
                temp[index] = A[left_start];
                index++;
                left_start++;
            }
            else
            {
                temp[index] = A[right_start];
                index++;
                right_start++;
            }
        }

        while(left_start<=left_end)
        {
            temp[index] = A[left_start];
            index++;
            left_start++;
        }

        while(right_start <= right_end)
        {
            temp[index] = A[right_start];
            index++;
            right_start++;
        }

        for(int i = start;i<=last;i++)
        {
            A[i] = temp[i];
        }
    }

    void merge_side(int A[], int temp[], int start, int last)
    {
        int middle = (last + start)/2;
        if(start < last)
        {
            merge_side(A, temp, start, middle);
            merge_side(A, temp, middle+1, last);
            s_merge(A, temp, start, middle, last);
        }
    }

    void merge_sort(int A[], int n)
    {
        int *temp = new int[n];
        merge_side(A, temp, 0, n-1);
    }
}

namespace QuickSort
{
    int get_Mid(int A[], int left, int right)
    {
        int mid = (left+right)/2;
        if(A[mid] < A[left])    swap(A[mid], A[left]);
        if(A[mid] > A[right])   swap(A[mid], A[right]);
        if(A[left] > A[right])  swap(A[left], A[right]);

        swap(A[mid], A[right-1]);

        return A[right-1];
    }

    void quicksort(int A[], int left, int right)
    {
        if((right-left) == 0)   return;
        int prov = get_Mid(A, left, right);

        int i = left+1;
        int j = right-2;
        while(i<j)
        {
            while(A[i]<prov)    i++;
            while(A[j]>prov)    j--;
            if(i<j) swap(A[i], A[j]);
            else    break;
        }
        swap(A[i], A[right-1]);
        quicksort(A, left, i-1);
        quicksort(A, i+1, right);

    }

    void Start_Quick_sort(int A[], int n)
    {
        quicksort(A, 0, n-1);
    }
}

int main()
{
    int a[7] = {4,2,3,51,4,3,7};
    QuickSort::Start_Quick_sort(a, 7);
    for(int i=0;i<7;i++)
    {
        cout<<a[i]<<" ";
    }
}
