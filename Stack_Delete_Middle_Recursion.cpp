#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

void Solve(Stack &stack, int size, int count)
{
    if (size / 2 == count)
    {
        stack.pop();
        return;
    }

    int temp = stack.peek();
    stack.pop();

    Solve(stack, size, count + 1);
    stack.push(temp);
}

void Delete_Middle(Stack &stack, int size)
{
    int count = 0;
    Solve(stack, size, count);
}

int main()
{
    Stack stack(6);
    int i = 0;

    while (i < 6)
    {
        stack.push(i + 1);
        i++;
    }

    Delete_Middle(stack, 5);

    while (stack.top >= 0)
    {
        cout << stack.peek() << "\t";
        stack.pop();
    }
}