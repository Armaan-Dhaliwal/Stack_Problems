/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.*/

#include <iostream>
using namespace std;
#include "Stack_Class_Array.cpp"

int *Prev_Smaller(int *heights, int size)
{
    Stack stack(size);
    stack.push(-1);
    int *ans = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (stack.peek() != -1)
        {
            while (heights[stack.peek()] >= heights[i] && stack.peek() != -1)
            {
                stack.pop();
            }
        }
        ans[i] = stack.peek();
        stack.push(i);
    }

    return ans;
}

int *Next_Smaller(int *heights, int size)
{
    Stack stack(size);
    stack.push(-1);
    int *ans = new int[size];

    int peeker = stack.peek();
    for (int i = size - 1; i >= 0; i--)
    {
        peeker = stack.peek();
        if (stack.peek() != -1)
        {
            while (heights[stack.peek()] >= heights[i] && stack.peek() != -1)
            {
                stack.pop();
            }
        }
        ans[i] = stack.peek();
        stack.push(i);
    }
    return ans;
}

int Largest_Rectangle(int *heights, int size)
{
    int *area = new int[size];

    int *next = new int[size];
    next = Next_Smaller(heights, size);

    int *prev = new int[size];
    prev = Prev_Smaller(heights, size);

    for (int i = 0; i < size; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = size;
        }

        int b = next[i] - prev[i] - 1;
        area[i] = l * b;
    }

    cout << "areas are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << area[i] << " " << endl;
    }

    int max = -1;
    for (int i = 0; i < size; i++)
    {
        if (area[i] > max)
        {
            max = area[i];
        }
    }

    return max;
}

int main()
{
    int size;
    cout << "Enter number of histograms: " << endl;
    cin >> size;
    int *heights = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> heights[i];
    }

    cout << "Heights are: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << heights[i] << " ";
    }

    int max_area = Largest_Rectangle(heights, size);
    cout << "Largest Rectangle is: " << max_area << endl;
}
