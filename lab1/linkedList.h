#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
private:
    class Node
    {
    public:
        T data;
        Node *next;
        Node *prev;

        Node(T value)
        {
            this->data = value;
            next = prev = NULL;
        }
    };

    Node *head;
    Node *tail;
    int count;

public:
    LinkedList()
    {
        head = tail = NULL;
        count = 0;
    }

    ~LinkedList()
    {
        Node *current = head;
        while (current != NULL)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push(T value)
    {
        Node *newNode = new Node(value);

        if (tail == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    T pop()
    {
        if (tail == NULL)
        {
            throw "the list is empty";
        }

        Node *temp = tail;
        T value = temp->data;

        if (head == tail)
        {
            head = tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
        count--;
        return value;
    }

    void insertAfter(int value, int newValue)
    {
        Node *current = head;
        while (current != NULL && current->data != value)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            Node *newNode = new Node(newValue);
            newNode->next = current->next;
            newNode->prev = current;

            if (newNode->next == NULL)
            {
                tail = newNode;
            }
            if (current->next != NULL)
            {
                current->next->prev = newNode;
            }

            current->next = newNode;
            count++;
        }
        else
        {
            throw "value not found";
        }
    }

    void insertBefore(int value, int newValue)
    {
        Node *current = head;
        while (current != NULL && current->data != value)
        {
            current = current->next;
        }

        if (current != NULL)
        {
            Node *newNode = new Node(newValue);
            newNode->prev = current->prev;
            newNode->next = current;

            if (current->prev != NULL)
            {
                current->prev->next = newNode;
            }
            else
            {
                head = newNode;
            }

            current->prev = newNode;
            count++;
        }
        else
        {
            throw "value not found";
        }
    }

    int getCount()
    {
        return count;
    }

    int getData(int index)
    {
        if (index < 0 || index >= count)
        {
            throw "index out of range";
        }
        if (head == NULL)
        {
            throw "list is empty";
        }

        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= count)
        {
            throw "index out of range";
        }
        if (head == NULL)
        {
            throw "list is empty";
        }

        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void reverse()
    {
        if (head == NULL || head->next == NULL)
        {
            return;
        }
        Node *current = head;
        Node *temp = NULL;

        while (current != NULL)
        {
            temp = current->next;

            current->next = current->prev;
            current->prev = temp;

            current = current->prev;
        }

        if (temp != NULL)
        {
            head = temp->prev;
            tail = temp;
        }
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "The list is empty." << endl;
            return;
        }

        Node *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

#endif
