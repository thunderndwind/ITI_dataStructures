#ifndef STACKLINKED_H
#define STACKLINKED_H
#include <iostream>
#include <cstddef>

using namespace std;

template <class T>
class StackLinked
{
private:
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T value)
        {
            data = value;
            next = NULL;
        }
    };

    Node *head;
    int count;

public:
    StackLinked()
    {
        head = NULL;
        count = 0;
    }

    ~StackLinked()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void push(T value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        count++;
    }

    T pop()
    {
        if (isEmpty())
            throw "Stack is empty";

        Node *tempNode = head;
        T value = head->data;
        head = head->next;
        delete tempNode;
        count--;
        return value;
    }

    T peek()
    {
        if (isEmpty())
            throw "Stack is empty";
        return head->data;
    }

    int getSize()
    {
        return count;
    }

    void reverse()
    {
        if (isEmpty())
            throw "Stack is empty";

        Node *prev = NULL;
        Node *current = head;
        Node *nextNode = NULL;

        while (current != NULL)
        {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }

    void display()
    {
        if (isEmpty())
            throw "Stack is empty!";

        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
};
#endif
