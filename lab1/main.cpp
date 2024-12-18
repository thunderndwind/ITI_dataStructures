#include "linkedList.h"
#include <iostream>

using namespace std;

int main()
{
    try
    {

        LinkedList<int> list;

        list.push(10); // 10

        list.insertAfter(10, 20); // 10 20
        list.insertAfter(20, 30); // 10 20 30

        list.insertBefore(20, 15); // 10 15 20  30
        list.insertBefore(15, 12); // 10 12 15 20 30

        cout << "list length: " << list.getCount() << endl; // 5

        cout << "index 1: " << list.getData(1) << endl; // 12

        cout << "index 2: " << list[2] << endl; // 15

        LinkedList<float> floatList;

        floatList.push(10);

        floatList.insertAfter(10, 20);
        floatList.insertAfter(20, 30);

        floatList.insertBefore(20, 15);
        floatList.insertBefore(15, 12);

        floatList.display();

        cout << "deleted element: " << floatList.pop() << endl;
        floatList.display();

        cout << "float list length: " << floatList.getCount() << endl;

        cout << "index 1: " << floatList.getData(1) << endl;

        cout << "index 2: " << floatList[2] << endl;
    }
    catch (char const *err)
    {
        cout << "Error" << err << endl;
    }

    return 0;
}
