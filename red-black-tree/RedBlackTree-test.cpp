#include <iostream>
#include "RedBlackTree.h"

using namespace std;

int main()
{
    RedBlackTree<int> tree;

    tree.insert(50);
    tree.insert(150);
    tree.insert(100);
    tree.insert(20);
    tree.insert(30);
    tree.insert(10);
    tree.insert(25);
    tree.insert(40);
    tree.insert(60);

    // lots of rotations involved in this one!
    tree.insert(70);

    cout << "inorder traversal of the tree: ";
    tree.inorder();
    cout << "\n" << endl;

    cout << "preorder traversal of the tree: ";
    tree.preorder();
    cout << "\n" << endl;

    return 0;
}
