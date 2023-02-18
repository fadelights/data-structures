#include <iostream>
#include "LinkedQueue.h"

using namespace std;

int main()
{
    LinkedQueue<int> q;

    q.enq(1);
    q.print();

    q.enq(2);
    q.print();

    q.deq();
    q.print();

    q.enq(3);
    q.enq(4);
    q.enq(5);
    q.enq(6);
    q.enq(7);
    
    q.print();

    cout << q.start() << endl;
    cout << q.end() << endl;

    return 0;
}
