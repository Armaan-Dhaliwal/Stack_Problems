#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

int *Next_Smaller(int *arr, int size)
{
    Stack stack(size);
    stack.push(-1);
    int *ans = new int[size];

    for (int i = size - 1; i >= 0; i--)
    {
        if (stack.peek() < arr[i])
        {
            ans[i] = stack.peek();
        }

        else
        {
            while (stack.peek() > arr[i])
            {
                stack.pop();
            }
            ans[i] = stack.peek();
        }

        stack.push(arr[i]);
    }

    return ans;
}

int main()
{
    int *arr;
    int size;
    cout << "Enter you array's size: " << endl;
    cin >> size;
    arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cout << "Enter your array: " << endl;
        cin >> arr[i];
    }

    int *ans = new int[size];
    ans = Next_Smaller(arr, size);
    cout << "Answer array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << "  ";
    }
}