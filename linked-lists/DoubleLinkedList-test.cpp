#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
    DoubleLinkedList<int> list;

    cout << list.isEmpty() << endl;

    /*******************************/

    list.addLast(10);
    list.print();

    list.addFirst(20);
    list.print();

    list.addLast(30);
    list.print();

    /*******************************/

    list.delFirst();
    list.print();

    list.delLast();
    list.print();

    list.delLast();
    list.print();

    /*******************************/

    cout << list.isEmpty() << endl;

    return 0;
}
