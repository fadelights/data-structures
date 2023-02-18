#include <iostream>
#include "LinkedStack.h"

using namespace std;

int main()
{
    LinkedStack<int> stack;
    
    cout << stack.isEmpty() << endl;
    
    stack.push(10);
    cout << stack.top() << endl;

    stack.push(20);
    cout << stack.top() << endl;

    stack.pop();
    cout << stack.top() << endl;

    cout << stack.isEmpty() << endl;

    return 0;
}
