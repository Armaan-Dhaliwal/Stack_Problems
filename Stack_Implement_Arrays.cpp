#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

int main()
{
    Stack S(4);
    S.push(1);
    S.push(2);
    S.push(3);
    S.push(4);
    S.push(5);
    S.push(6);

    cout << "Element at top is: " << S.peek() << endl;

    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    S.pop();

    cout << "Element at top is: " << S.peek() << endl;

    if (S.IsEmpty())
    {
        cout << "Yes Stack is indeed Empty " << endl;
    }
    else
        cout << "Stack is not Empty yet " << endl;
}