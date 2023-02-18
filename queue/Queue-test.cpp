#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q(5);

    q.enq(1);
    cout << q.front()<< ", " << q.rear() << endl;

    q.enq(25);
    cout << q.front()<< ", " << q.rear() << endl;

    q.enq(37);
    cout << q.front()<< ", " << q.rear() << endl;

    q.enq(43);
    cout << q.front()<< ", " << q.rear() << endl;

    q.deq();
    cout << q.front()<< ", " << q.rear() << endl;

    q.deq();
    cout << q.front()<< ", " << q.rear() << endl;

    return 0;
}
