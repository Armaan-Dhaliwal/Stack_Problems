#include <iostream>
using namespace std;
#include "Stack_Node_Class.cpp"

Node *push(Node *head, int ele)
{
    Node *newNode = new Node(ele);
    if (head == NULL)
    {
        head = newNode;
    }

    else
    {
        newNode->next = head;
        head = newNode;
    }
    return head;
}

int peek(Node *head)
{
    if (head != NULL)
    {
        return head->data;
    }
    else
        return -1;
}

Node *pop(Node *head)
{
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        cout << "Stack Underflow " << endl;
    }

    return head;
}

bool IsEmpty(Node *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    Node *head = NULL;
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    cout << "Element at the top is: " << peek(head) << endl;
    head = pop(head);
    cout << "Element at the top is: " << peek(head) << endl;
    head = pop(head);
    cout << "Element at the top is: " << peek(head) << endl;
    if (IsEmpty(head))
    {
        cout << " Stack is empty " << endl;
    }
    else
        cout << "Stack is not empty just yet " << endl;
}