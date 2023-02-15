#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

bool Check_Validity(string str)
{
    Stack stack(str.length());
    int i = 0;

    while (str[i] != '\0')
    {

        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
            stack.push(str[i]);
        }

        else
        {
            if (!stack.IsEmpty())
            {
                if (stack.peek() == '{' && str[i] == '}' || stack.peek() == '[' && str[i] == ']' || stack.peek() == '(' && str[i] == ')')
                {
                    stack.pop();
                }

                else
                {
                    return false;
                }
            }

            else
            {
                return false;
            }
        }

        i++;
    }

    if (stack.IsEmpty())
    {
        return true;
    }

    else
        return false;
}

int main()
{
    string str = "[]{}())";

    if (Check_Validity(str))
    {
        cout << "\n Balanced " << endl;
    }

    else
        cout << "\n Unabalanced " << endl;
}