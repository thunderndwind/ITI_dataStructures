#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <iostream>
using namespace std;

template <class T>
class StackArray
{
private:
    T *elements;
    int top;
    int size;

public:
    StackArray(int size = 10)
    {
        this->size = size;
        elements = new T[size];
        top = -1;
    }

    ~StackArray()
    {
        delete[] elements;
    }

    StackArray(const StackArray<T> &other)
    {
        size = other.size;
        top = other.top;
        elements = new T[size];
        for (int i = 0; i < top; ++i)
        {
            elements[i] = other.elements[i];
        }
    }

    StackArray<T> operator=(const StackArray<T> &other)
    {
        if (this != &other)
        {
            delete[] elements;
            size = other.size;
            top = other.top;
            elements = new T[size];
            for (int i = 0; i < top; ++i)
            {
                elements[i] = other.elements[i];
            }
        }
        return *this;
    }

    bool operator==(const StackArray<T> &other) const
    {
        if (top != other.top)
        {
            return false;
        }
        for (int i = 0; i < top; ++i)
        {
            if (elements[i] != other.elements[i])
            {
                return false;
            }
        }
        return true;
    }

    void resize(int new_capacity)
    {
        T *new_arr = new T[new_capacity];
        for (int i = 0; i < top; ++i)
        {
            new_arr[i] = elements[i];
        }
        delete[] elements;
        elements = new_arr;
        size = new_capacity;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == size - 1;
    }

    void push(T value)
    {
        if (this->isFull())
            throw "Stack is full";

        elements[++top] = value;
    }

    T pop()
    {
        if (this->isEmpty())
            throw "Stack is empty";

        return elements[top--];
    }

    T peek()
    {
        if (this->isEmpty())
            throw "Stack is empty";

        return elements[top];
    }

    int getSize()
    {
        return top + 1;
    }
    int getCapacity()
    {
        return size;
    }

    void reverse()
    {
        if (this->isEmpty())
            throw "Queue is empty";

        T *temp = new T[this->size];
        int i = top;
        int j = 0;
        while (i >= 0)
        {
            temp[j++] = elements[i--];
        }
        delete[] elements;

        this->elements = temp;
    }
    void display()
    {
        if (this->isEmpty())
            throw "Stack is empty!";

        for (int i = top; i >= 0; i--)
            cout << elements[i] << "\t";

        cout << endl;
    }
};
#endif
