#include <iostream>
#include "TwoThreeTree.h"

#define ARR_SIZE(x) sizeof(x) / sizeof(x[0])

using namespace std;

int main()
{
    TwoThreeTree<int> t;

    int vals[] = {50, 60, 70, 40, 30, 20, 10, 80, 90, 100, 95, 75, 78, 72, 74};
    for (unsigned int i = 0; i < ARR_SIZE(vals); i++)
    {
        cout << "inserting " << vals[i] << endl;
        t.insert(vals[i]);

        t.sortedorder();
        cout << endl;
        t.preorder();
        cout << '\n' << endl;
    }

    return 0;
}
