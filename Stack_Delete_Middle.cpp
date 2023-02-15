#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

void Delete_Middle(Stack &stack, int size)
{
    Stack temp_stack(size / 2);
    int count = 0;
    int temp;
    while (count != size / 2)
    {
        temp = stack.peek();
        stack.pop();
        temp_stack.push(temp);
        count++;
    }

    cout << "Stack top is: " << stack.peek() << endl;
    stack.pop();
    while (!temp_stack.IsEmpty())
    {
        temp = temp_stack.peek();
        temp_stack.pop();
        stack.push(temp);
    }
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