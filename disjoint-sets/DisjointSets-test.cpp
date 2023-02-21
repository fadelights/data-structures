#include <iostream>
#include "DisjointSets.h"

using namespace std;

int main()
{
    try
    {
        DisjointSets ds(10);

        // ds.simpleUnion(4, 7);
        // ds.simpleUnion(9, 2);
        // ds.simpleUnion(1, 3);
        // ds.simpleUnion(8, 6);
        // ds.simpleUnion(7, 1);
        // ds.simpleUnion(6, 2);
        // ds.simpleUnion(0, 5);
        // ds.simpleUnion(0, 1);
        // ds.simpleUnion(9, 7);

        ds.weightedUnion(1, 2);
        ds.weightedUnion(3, 4);
        ds.weightedUnion(5, 6);
        ds.weightedUnion(7, 8);
        ds.weightedUnion(9, 0);
        ds.weightedUnion(1, 8);
        ds.weightedUnion(3, 8);
        ds.weightedUnion(5, 8);
        ds.weightedUnion(7, 8);
        ds.weightedUnion(9, 8);

        cout << ds.collapsingFind(9) << endl;

        ds.printSets();
    }

    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    return 0;
}
