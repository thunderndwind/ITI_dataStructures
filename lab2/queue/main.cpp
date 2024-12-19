#include "queueArray.h"
#include "queueLinked.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        // Test QueueArray
        /*
        QueueArray<int> queue(4);

        for (int i = 0; i < 4; i++)
            queue.enqueue(i + 1);
        queue.display();

        for (int i = 0; i < 2; i++)
            cout << queue.dequeue() << "\t";
        queue.display();

        for (int i = 0; i < 2; i++)
            queue.enqueue(i + 5);

        queue.display();

        for (int i = 0; i < 4; i++)
            cout << queue.dequeue() << "\t";
        */
        QueueArray<int> queue(6);

        for (int i = 0; i < 4; i++)
            queue.enqueue(i + 1);

        for (int i = 0; i < 2; i++)
            queue.enqueue(i + 5);

        queue.display();
        queue.reverse();
        queue.display();

        for (int i = 0; i < 4; i++)
            cout << queue.dequeue() << "\t";
        cout << endl;

        for (int i = 0; i < 2; i++)
            queue.enqueue(i + 5);

        for (int i = 0; i < 4; i++)
            cout << queue.dequeue() << "\t";
        // Test QueueLinked
        /*
        QueueLinked<int> queue;

        for (int i = 0; i < 4; i++)
            queue.enqueue(i + 1);

        for (int i = 0; i < 2; i++)
            queue.enqueue(i + 5);

        queue.display();
        queue.reverse();
        queue.display();

        for (int i = 0; i < 4; i++)
            cout << queue.dequeue() << "\t";
        */
    }
    catch (char const *err)
    {
        cout << "Caught Error: " << err << endl;
    }

    return 0;
}
