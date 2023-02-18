#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
    LinkedList<int> list;

    try
    {
        cout << list.isEmpty() << endl;

        list.sortedInsert(50);
        list.print();
        list.sortedInsert(20);
        list.print();

        list.addHead(10);
        list.print();
        list.addHead(5);
        list.print();

        list.sortedInsert(25);
        list.print();

        list.delHead();
        list.print();

        list.sortedInsert(60);
        list.print();
    }

    catch (const runtime_error& error)
    {
        cout << error.what() << endl;
    }

    return 0;
}