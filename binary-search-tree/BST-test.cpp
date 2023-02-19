#include <iostream>
#include "BST.h"

using namespace std;

int main()
{
    BinarySearchTree<int> bst;
    int input, key;
    while (true)
    {
        cout << " ----------------------------- " << endl;
        cout << " Binary Search Tree Operations " << endl;
        cout << " ----------------------------- " << endl;
        cout << " 1. Insert " << endl;
        cout << " 2. Search " << endl;
        cout << " 3. Remove " << endl;
        cout << " 4. In-Order Traversal " << endl;
        cout << " 5. Pre-Order Traversal " << endl;
        cout << " 6. Post-Order Traversal " << endl;
        cout << " 0. Exit " << endl;

        cout << "\t Enter your choice : ";
        cin >> input;

        switch (input)
        {
            case 1:
                cout << "\t Enter key to insert: ";
                cin >> key;
                bst.insert(key);
                break;
            
            case 2:
                cout << "\t Enter key to search: ";
                cin >> key;
                if (bst.search(key))
                    cout << "\t Key found." << endl;
                else
                    cout << "\t Key not found.";
                break;
            
            case 3:
                cout << "\t Enter key to delete: ";
                cin >> key;
                if (bst.remove(key))
                    cout << "\t " << key << " was successfully removed." << endl;
                else
                    cout << "\t there is no " << key << " in the tree." << endl;
                break;
            
            case 4:
                cout << "\t In-Order Traversal " << endl;
                cout << "\t ------------------ " << endl << "\t";
                bst.inorder();
                cout << endl;
                break;
            
            case 5:
                cout << "\t Pre-Order Traversal " << endl;
                cout << "\t ------------------- " << endl << "\t";
                bst.preorder();
                cout << endl;
                break;
            
            case 6:
                cout << "\t Post-Order Traversal " << endl;
                cout << "\t -------------------- " << endl << "\t";
                bst.postorder();
                cout << endl;
                break;
            
            case 0:
                return 0;
            
            default:
                cout << "\t Please try again." << endl;
                break;
        }
    }
}
