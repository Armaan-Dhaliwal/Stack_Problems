#include <iostream>
using namespace std;

class Stack
{

public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele)
    {
        if (top < size)
        {
            top++;
            arr[top] = ele;
        }
        else
            cout << "Stack Overflow " << endl;
    }

    void pop()
    {
        if (top >= 0)
        {
            top--;
        }
        else
            cout << "Stack Underflow " << endl;
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }

        else
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    bool IsEmpty()
    {
        if (top == -1)
        {
            return true;
        }

        else
            return false;
    }
};