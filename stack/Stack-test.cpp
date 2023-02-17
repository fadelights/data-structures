#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack<char> s(5);

    s.push('a');
    cout << s.getTopIndex() << ", " << s.getTopItem() << endl;

    s.push('f');
    cout << s.getTopIndex() << ", " << s.getTopItem() << endl;

    s.push('r');
    cout << s.getTopIndex() << ", " << s.getTopItem() << endl;

    s.pop();
    cout << s.getTopIndex() << ", " << s.getTopItem() << endl;

    s.pop();
    cout << s.getTopIndex() << ", " << s.getTopItem() << endl;

    return 0;
}
