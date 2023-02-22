#include <iostream>
#include <ctime>
#include <cstdlib>
#include "SkipList.h"

using namespace std;

int main()
{
    srand(time(NULL));
    SkipList<int> sl;

    int list[] = {4, 1, 5, 8, 9, 3, 2, 0, 7, 6};
    int length{sizeof(list) / sizeof(int)};
    for (int index{0}; index < length; index++)
    {
        sl.insert(list[index]);
    }
    
    sl.print();

    int numOfRemovals{3};
    int temp;
    bool flag;
    for (int i = 0; i < numOfRemovals; i++)
    {
        cout << "input number to remove: ";
        cin >> temp;
        
        cout << "removing " << temp << "... ";
        flag = sl.remove(temp);
        
        if (flag)
        {
            cout << "success." << endl;
            sl.print();
        }

        else
            cout << "fail." << endl;
    }

    return 0;
}
