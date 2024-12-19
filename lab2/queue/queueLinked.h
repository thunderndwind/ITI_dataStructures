#ifndef QUEUELINKED_H
#define QUEUELINKED_H
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
class QueueLinked
{
private:
    class Node
    {
    public:
        T data;
        Node *next;

        Node(T value)
        {
            this->data = value;
            next = NULL;
        }
    };

    Node *front;
    Node *rear;
    int count;

public:
    QueueLinked()
    {
        front = rear = NULL;
        count = 0;
    }

    ~QueueLinked()
    {
        Node *current = front;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool isEmpty()
    {
        if (front == rear && front == NULL)
            return 1;
        return 0;
    }

    void enqueue(T value)
    {
        Node *newNode = new Node(value);
        if (this->isEmpty())
            front = rear = newNode;

        else
        {
            rear->next = newNode;
            rear = newNode;
        }

        count++;
    }

    T dequeue()
    {
        if (this->isEmpty())
            throw "Queue Is Empty";

        Node *tempNode = front;
        T tempValue = front->data;
        front = front->next;
        if (front == NULL)
            rear = NULL;

        delete tempNode;
        count--;
        return tempValue;
    }

    int getSize()
    {
        return count;
    }

    T getFront()
    {
        if (this->isEmpty())
            throw "Queue is empty";
        return front->data;
    }

    T getRear()
    {
        if (this->isEmpty())
            throw "Queue is empty";
        return rear->data;
    }

    void reverse()
    {
        if (this->isEmpty())
            return;

        Node *prev = NULL;
        Node *current = front;
        Node *next = NULL;

        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        rear = front;
        front = prev;
    }

    void display()
    {
        if (this->isEmpty())
            throw "Queue is empty, nothing to display";

        Node *current = front;
        while (current != NULL)
        {
            cout << current->data << "\t";
            current = current->next;
        }
        cout << endl;
    }
};

#endif
