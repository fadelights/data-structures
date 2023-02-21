#include <iostream>
#include <vector>
#include "MinHeap.h"

using namespace std;

int main()
{
    int a[] {2, 1, 7, 0, 4, 3, 9, 8, 5, 6};
    vector<int> v {2, 1, 7, 0, 4, 3, 9, 8, 5, 6};

    MinHeap<int> h1(a, sizeof(a) / sizeof(int));
    MinHeap<int> h2;

    h1.show();

    for (const int& item: v)
        h2.insert(item);

    h2.show();

    cout << h2.min() << endl;
    
    for (int i{0}; i < sizeof(h2) / sizeof(int); i++)
    {
        cout << h2.extractMin() << endl;
        h2.show();
    }

    h2.decreaseKey(1, -1);
    h2.show(); 

    h2.extractMin();
    h2.show();
    h2.extractMin();
    h2.show();

    try
    {
        h2.extractMin();
    }

    catch (const exception& err)
    {
        cout << err.what() << endl;
    }

    h1.sort();
    h1.show(v.size());

    return 0;
}
