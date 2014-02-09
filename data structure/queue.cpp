/***************************************
The code of queue in linked list mathod.
****************************************/

#include <iostream>
using namespace std;

typedef struct lnode
{
    int value;
    struct lnode* next;
}node;

node* head;
node* tail;
int node_count;

bool push(int num)
{
    node* new_node = new node;
    new_node->value = num;

    if(node_count == 0)
    {
        head = new_node;
        tail = new_node;
        new_node->next = NULL;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
        new_node->next = NULL;
    }
    node_count++;

    return true;


}

int pop()
{
    int value = head->value;

    if(node_count == 1)
    {
        delete head;
        node_count--;
        return value;
    }
    else
    {
        node* temp = head;
        head = head->next;
        node_count--;
        delete temp;
    }
    return value;
}

int get_number()
{
    return node_count;
}

void print_element()
{
    node* ptr = head;
    while(ptr != NULL)
    {
        cout<<ptr->value<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
}

int main()
{
    head = NULL;
    tail = NULL;
    node_count = 0;

    while(true)
    {
        cout<<"Please choose the option:"<<endl;
        cout<<"1. Push a new element;"<<endl;
        cout<<"2. Pop a element;"<<endl;
        cout<<"3. Show the number of current queue;"<<endl;
        cout<<"4. Print all the elements in queue;"<<endl;
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
            if(node_count == 0)    cout<<"The stack is empty"<<endl;
            else    cout<<"The number "<<pop()<<" is deleted"<<endl;
            continue;
        case 3:
            cout<<"the current number in stack is "<<get_number()<<endl;
            continue;
        case 4:
            if(node_count == 0)    cout<<"The stack is empty."<<endl;
            else print_element();
            continue;
        case 5:
            return 0;
        }
    }

}

