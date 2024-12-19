#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
class QueueArray
{
private:
    int front;
    int rear;
    T *elements;
    int size;
    int count;

public:
    QueueArray(int size = 10)
    {
        front = rear = -1;
        count = 0;
        this->size = size;
        elements = new T[this->size];
    }

    ~QueueArray()
    {
        delete[] elements;
    }

    bool isEmpty() // enhance using size and count
    {
        // if (front == rear && front == -1)
        //     return 1;
        return count == 0;
    }

    bool isFull() // enhance using size and count
    {
        // if ((rear + 1) % size == front)
        //     return 1;
        return count == size;
    }

    void enqueue(T value)
    {

        if (this->isFull())
            throw "Queue Is Full";

        else if (this->isEmpty())
            front = rear = 0;

        else
            rear = (rear + 1) % size;

        this->elements[rear] = value;
        count++;
    }

    T dequeue()
    {

        if (this->isEmpty())
            throw "Queue Is Empty";

        T element = this->elements[front];

        // if (rear == front) // find another way
        //  front = rear = -1;

        if (rear != front)
            front = ((front + 1) % size);
        count--;
        return element;
    }

    int getSize()
    {
        return count;
    }

    int getCapacity()
    {
        return size;
    }

    T getFront()
    {
        if (this->isEmpty())
            throw "Queue is empty";
        return elements[front];
    }

    T getRear()
    {
        if (this->isEmpty())
            throw "Queue is empty";
        return elements[rear];
    }

    void reverse()
    {
        if (this->isEmpty())
            throw "Queue is empty";

        T *temp = new T[this->size];

        int i = front;
        int j = count - 1;

        do
        {
            temp[j] = elements[i];
            i = ((i + 1) % size);
            j--;

        } while (i != ((rear + 1) % size));

        delete[] elements;

        this->elements = temp;
        this->front = 0;
        this->rear = count - 1;
    }

    void display()
    {
        if (this->isEmpty())
        {
            throw "Queue is empty";
        }

        cout << "\n================== In Display ====================\n";

        int i = front;
        do
        {
            cout << elements[i] << "\t";
            i = ((i + 1) % size);

        } while (i != ((rear + 1) % size));

        cout << "\n================== Outing Display ====================\n";
    }
};
#endif
