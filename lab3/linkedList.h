#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
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

template <class T>
class LinkedList
{
private:
    Node<T> *head;
    Node<T> *tail;
    int count;

    Node<T> *findNode(int value)
    {
        Node<T> *current = head;
        while (current != NULL && current->data != value)
        {
            current = current->next;
        }
        return current;
    }

public:
    LinkedList()
    {
        head = tail = NULL;
        count = 0;
    }

    ~LinkedList()
    {
        Node<T> *current = head;
        while (current != NULL)
        {
            Node<T> *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void push(T value)
    {
        Node<T> *newNode = new Node<T>(value);

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

        Node<T> *temp = tail;
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
    Node<T> *getHead() const
    {
        return head;
    }

    Node<T> *getTail() const
    {
        return tail;
    }
    Node<T> *remove(Node<T> *node)
    {
        if (node == NULL)
            return NULL;

        if (node->prev != NULL)
            node->prev->next = node->next;

        else
            head = node->next;

        if (node->next != NULL)
            node->next->prev = node->prev;

        else
            tail = node->prev;

        count--;
        node->next = node->prev = NULL;
        return node;
    }

    void insertAfter(int value, int newValue)
    {
        Node<T> *current = findNode(value);

        // while (current != NULL && current->data != value)
        // {
        //     current = current->next;
        // }

        if (current != NULL)
        {
            Node<T> *newNode = new Node<T>(newValue);
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
        Node<T> *current = findNode(value);
        // while (current != NULL && current->data != value) // change to a method to find speceific node
        // {
        //     current = current->next;
        // }

        if (current != NULL)
        {
            Node<T> *newNode = new Node<T>(newValue);
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

    // add insert to index
    // join and + operator overload
    void insertAtIndex(int index, T value)
    {
        if (index < 0 || index > count)
        {
            throw "index out of range";
        }

        if (index == 0)
        {
            Node<T> *newNode = new Node<T>(value);
            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
            count++;
            return;
        }

        if (index == count)
        {
            push(value);
            return;
        }

        Node<T> *current = NULL;
        if (index <= count / 2)
        {
            current = head;
            for (int i = 0; i < index; i++)
            {
                current = current->next;
            }
        }
        else
        {
            current = tail;
            for (int i = count; i > index; i--)
            {
                current = current->prev;
            }
        }

        Node<T> *newNode = new Node<T>(value);
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        count++;
    }

    LinkedList<T> &operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            Node<T> *current = other.head;
            while (current != NULL)
            {
                push(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    LinkedList<T> operator+(const LinkedList<T> &other) const
    {
        LinkedList<T> result;

        Node<T> *current = head;
        while (current != NULL)
        {
            result.push(current->data);
            current = current->next;
        }

        current = other.head;
        while (current != NULL)
        {
            result.push(current->data);
            current = current->next;
        }

        return result;
    }

    void join(const LinkedList<T> &other)
    {
        Node<T> *current = other.head;
        while (current != NULL)
        {
            push(current->data);
            current = current->next;
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

        Node<T> *current = head;
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

        Node<T> *current = head;
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
        Node<T> *current = head;
        Node<T> *temp = NULL;

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
            throw "The list is empty.";
        }

        Node<T> *current = head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    Node<T> *binarySearch(T value)
    {
        Node<T> *start = head;
        Node<T> *end = tail;

        while (start != NULL && end != NULL && start != end && start != end->next)
        {
            Node<T> *mid = start;
            Node<T> *temp = start;
            int count = 0;
            while (temp != end)
            {
                temp = temp->next;
                count++;
            }
            for (int i = 0; i < count / 2; i++)
                mid = mid->next;

            if (mid->data == value)
                return mid;

            else if (mid->data < value)
                start = mid->next;

            else
                end = mid->prev;
        }
        return NULL;
    }
};

#endif
