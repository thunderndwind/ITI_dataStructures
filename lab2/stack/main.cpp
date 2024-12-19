#include "stackArray.h"
#include "stackLinked.h"

#include <iostream>

using namespace std;

int main()
{
    try
    {
        // Test StackLinked
        /*
         */
        StackLinked<int> stackLinked;
        stackLinked.push(1);
        stackLinked.push(2);
        stackLinked.push(3);
        stackLinked.push(4);

        stackLinked.display();
        stackLinked.reverse();
        stackLinked.display();

        cout << "Element Out: " << stackLinked.pop() << endl;
        stackLinked.display();

        // Test StackArray
        /*
        StackArray<int> stackArray(5);
        stackArray.push(5);
        stackArray.push(10);
        stackArray.push(15);
        stackArray.display();
        cout << "Element Out: " << stackArray.pop() << endl;
        stackArray.display();
        stackArray.reverse();
        stackArray.display();
        */
    }
    catch (char const *err)
    {
        cout << "Caught Error: " << err << endl;
    }

    return 0;
}
