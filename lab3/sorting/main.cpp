#include <iostream>
#include "sorting.h"

using namespace std;

int main()
{
    int arr[] = {10, 20, 5, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    Sorting<int>::bubbleSortArray(arr, size);
    cout << "Sorted Array (Bubble Sort): ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr2[] = {10, 20, 5, 8, 15};

    cout << "Original Array: ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    Sorting<int>::mergeSortArray(arr2, 0, size - 1);
    cout << "Sorted Array (Merge Sort): ";
    for (int i = 0; i < size; ++i)
    {
        cout << arr2[i] << " ";
    }
    cout << endl
         << endl
         << endl;

    // --------------------------

    LinkedList<int> list;
    list.push(10);
    list.push(20);
    list.push(5);
    list.push(8);
    list.push(15);

    cout << "Original Linked List: ";
    list.display();

    Sorting<int>::bubbleSortSwapData(list);
    cout << "Sorted Linked List (Bubble Sort - Swap Data): ";
    list.display();

    cout << "Search Linked List using binary search: ";
    cout << list.binarySearch(10)->data << endl;

    Sorting<int>::bubbleSortNodes(list);
    cout << "Sorted Linked List (Bubble Sort - Swap Nodes): ";
    list.display();

    return 0;
}
