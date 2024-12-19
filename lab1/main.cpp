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

        LinkedList<int> list2;

        list2.push(40);
        list2.push(50);
        list2.push(60);

        list.join(list2);

        cout << "list elements: \n";
        list.display();

        list2.insertAtIndex(0, 35);
        cout << "list elements: \n";
        list2.display();
        LinkedList<int> list3;
        list3 = list + list2;

        cout << "list3 elements: \n";
        list3.display();
    }
    catch (char const *err)
    {
        cout << "Error" << err << endl;
    }

    return 0;
}
