/********************************
The code of stack in array mathod.
*********************************/

#include <iostream>
using namespace std;
#define MAX_NUM 10

int new_stack[MAX_NUM];
int *head;
int tail;

bool push(int num)
{
    if(tail == (MAX_NUM-1))     return false;

    if(tail == -1)
    {
        new_stack[0] = num;
        tail = 0;
    }
    else
    {
        new_stack[tail+1] = num;
        tail++;
    }

    return true;
}

int pop()
{
    if(tail == 0)
    {
        int value = new_stack[0];
        tail = -1;
        return value;
    }
    else
    {
        int value = new_stack[tail];
        tail--;
        return value;
    }
}

int get_number()
{
    if(tail == -1)    return 0;
    else    return tail+1;
}

void print_element()
{
    for(int i=0;i<=tail;i++)
    {
        cout<<new_stack[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    head = &new_stack[0];
    tail = -1;

    while(true)
    {
        cout<<"Please choose the option:"<<endl;
        cout<<"1. Push a new element;"<<endl;
        cout<<"2. Pop a element;"<<endl;
        cout<<"3. Show the number of current stack;"<<endl;
        cout<<"4. Print all the elements in stack;"<<endl;
        cout<<"5. Exit."<<endl;
        int option;
        cin>>option;
        switch(option)
        {
        case 1:
            cout<<"Input the number you want to push:";
            int num;
            cin>>num;
            if(push(num))   cout<<"push successful"<<endl;
            else    cout<<"The number of stack has exceeded the max num."<<endl;
            continue;
        case 2:
            if(tail == -1)    cout<<"The stack is empty"<<endl;
            else    cout<<"The number "<<pop()<<" is deleted"<<endl;
            continue;
        case 3:
            cout<<"the current number in stack is "<<get_number()<<endl;
            continue;
        case 4:
            if(tail == -1)    cout<<"The stack is empty."<<endl;
            else print_element();
            continue;
        case 5:
            return 0;
        }
    }

}

