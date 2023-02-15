#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

int main()
{
    string str = "Armaan";
    // char ans[10] = "";
    string ans = "";

    Stack stack(10);
    int i = 0;
    while (str[i] != '\0')
    {
        stack.push(str[i]);
        i++;
    }

    i = 0;
    while (!stack.IsEmpty())
    {
        char temp = stack.peek();
        // ans[i] = temp;
        ans = ans + temp;
        stack.pop();
        i++;
    }

    cout << "Reversed string is : " << ans << endl;
}