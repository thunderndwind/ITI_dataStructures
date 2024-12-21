#ifndef SORTING_H
#define SORTING_H
#include "../linkedList.h"
#include <vector>
#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static void swapElement(T &element1, T &element2)
    {
        T temp = element2;
        element2 = element1;
        element1 = temp;
    }

    static void swapData(Node<T> *node1, Node<T> *node2)
    {
        T temp = node1->data;
        node1->data = node2->data;
        node2->data = temp;
    }

    static int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++)
        {
            if (arr[j] <= pivot)
            {
                i++;
                swapElement(arr[i], arr[j]);
            }
        }

        swapElement(arr[i + 1], arr[high]);

        return (i + 1);
    }

    static void merge(int arr[], int left, int mid, int right)
    {
        int i, j, k;
        int n1 = mid - left + 1;
        int n2 = right - mid;

        int *leftArr = new int[n1];
        int *rightArr = new int[n2];

        for (i = 0; i < n1; i++)
            leftArr[i] = arr[left + i];
        for (j = 0; j < n2; j++)
            rightArr[j] = arr[mid + 1 + j];

        i = 0;
        j = 0;
        k = left;
        while (i < n1 && j < n2)
        {
            if (leftArr[i] <= rightArr[j])
            {
                arr[k] = leftArr[i];
                i++;
            }
            else
            {
                arr[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = rightArr[j];
            j++;
            k++;
        }
        delete[] leftArr;
        delete[] rightArr;
    }

public:
    static void bubbleSortArray(T arr[], int size)
    {
        bool swapped;
        do
        {
            swapped = false;
            for (int i = 1; i < size; ++i)
            {
                if (arr[i - 1] > arr[i])
                {
                    swapElement(arr[i - 1], arr[i]);
                    swapped = true;
                }
            }
            --size;
        } while (swapped);
    }

    static void selectionSortArray(T arr[], int size)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j)
            {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            if (minIndex != i)
                swapElement(arr[i], arr[minIndex]);
        }
    }

    static void insertionSortArray(T arr[], int size)
    {
        for (int i = 1; i < size; ++i)
        {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    static void quickSortArray(int arr[], int low, int high)
    {
        if (low < high)
        {
            int pi = partition(arr, low, high);
            quickSortArray(arr, low, pi - 1);
            quickSortArray(arr, pi + 1, high);
        }
    }

    static void mergeSortArray(int arr[], int left, int right)
    {
        if (left < right)
        {
            int mid = left + (right - left) / 2;

            mergeSortArray(arr, left, mid);
            mergeSortArray(arr, mid + 1, right);

            merge(arr, left, mid, right);
        }
    }

    // addition

    static int linearSearch(int arr[], int size, int target, vector<int> &foundIndices)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == target)
            {
                foundIndices.push_back(i);
            }
        }
        return foundIndices.size();
    }
    static void bubbleSortSwapData(LinkedList<T> &list)
    {
        if (list.getCount() <= 1)
            return;

        bool swapped;
        do
        {
            swapped = false;
            Node<T> *current = list.getHead();
            while (current != NULL && current->next != NULL)
            {
                if (current->data > current->next->data)
                {
                    swapData(current, current->next);
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }

    static void bubbleSortNodes(LinkedList<T> &list)
    {
        if (list.getCount() <= 1)
            return;

        bool swapped;
        do
        {
            swapped = false;
            auto current = list.getHead();
            while (current != NULL && current->next != NULL)
            {
                if (current->data > current->next->data)
                {
                    Node<T> *node1 = current;
                    Node<T> *node2 = current->next;

                    if (node1->prev != NULL)
                        node1->prev->next = node2;
                    if (node2->next != NULL)
                        node2->next->prev = node1;

                    node1->next = node2->next;
                    node2->prev = node1->prev;

                    if (node1 == list.getHead())
                        node2 = list.getHead();
                    if (node2 == list.getTail())
                        node1 = list.getTail();

                    node1->prev = node2;
                    node2->next = node1;

                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};

#endif