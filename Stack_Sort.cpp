#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

void Sorted_Insertion(Stack &stack, int n)
{
    if (stack.IsEmpty())
    {
        stack.push(n);
        return;
    }

    if (!stack.IsEmpty() && stack.peek() <= n)
    {
        stack.push(n);
        return;
    }

    int temp = stack.peek();
    stack.pop();
    Sorted_Insertion(stack, n);
    stack.push(temp);
}

void Sort_Stack(Stack &stack)
{
    if (stack.IsEmpty())
    {
        return;
    }

    int temp = stack.peek();
    stack.pop();
    Sort_Stack(stack);
    Sorted_Insertion(stack, temp);
}

int main()
{
    int num;
    cout << "Enter number of elements in stack: " << endl;
    cin >> num;

    Stack stack(num);
    cout << "enter numbers : " << endl;
    for (int i = 0; i < num; i++)
    {
        int temp;
        cin >> temp;
        stack.push(temp);
    }

    int temp_top = stack.top;

    cout << "Your original stack: " << endl;
    while (!stack.IsEmpty())
    {
        cout << stack.peek() << endl;
        stack.top--;
    }

    stack.top = temp_top;

    Sort_Stack(stack);
    cout << "Your updated stack: " << endl;
    while (!stack.IsEmpty())
    {
        cout << stack.peek() << endl;
        stack.top--;
    }
    stack.top = temp_top;
}