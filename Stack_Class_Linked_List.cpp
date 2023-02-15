#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
public:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int ele)
    {

        if (top == NULL && top->next == NULL)
        {
            Node *newNode = new Node(ele);
            top = newNode;
        }

        else if (top != NULL && top->next != NULL)
        {
            Node *tail = top;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }

            Node *newNode = new Node(ele);
            tail->next = newNode;
        }
    }

    int peek()
    {
    }
};