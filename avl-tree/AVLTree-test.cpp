#include <iostream>
#include "AVLTree.h"

using namespace std;

int main()
{
    AVLTree<int> tree;

    tree.insert(100);
    tree.insert(150);
    tree.insert(50);
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(200);
    tree.insert(120);
    tree.insert(110);
    tree.insert(160);
    tree.insert(130);
    tree.insert(40);
    tree.insert(10);
    tree.insert(120);

    cout << '\n' << "In-order Traversal: " << endl;
    tree.inorder();

    cout << '\n' << "Pre-order Traversal: " << endl;
    tree.preorder();

    cout << '\n' << "Post-order Traversal: " << endl;
    tree.postorder();

    cout << endl;

    return 0;
}
