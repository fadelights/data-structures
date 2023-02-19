#include "BinaryTreeNode.h"
#include <iostream>

template <typename T>
class BinarySearchTree
{
    public:
        BinarySearchTree();

        bool isEmpty() const;
        void insert(const T&);
        BinaryTreeNode<T>* search(const T&) const;
        bool remove(const T&);

        void inorder() const;
        void inorder(BinaryTreeNode<T>*) const;
        void preorder() const;
        void preorder(BinaryTreeNode<T>*) const;
        void postorder() const;
        void postorder(BinaryTreeNode<T>*) const;

    private:
        BinaryTreeNode<T>* root;
};

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
    : root(nullptr)
{
    // Empty
}

template <typename T>
bool BinarySearchTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value)
{
    // Make a new node
    BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);

    // Case 1: Tree is empty
    if (isEmpty())
    {
        root = newNode;
        return;
    }

    // Case 2: Tree is not empty
    BinaryTreeNode<T>* current = root;
    BinaryTreeNode<T>* parent = nullptr;

    // Search for the position of new key
    while (current)
    {
        parent = current;

        if (value >= current->key())
            current = current->right();
        
        else
            current = current->left();
    }

    if (value >= parent->key())
        parent->setRight(newNode);
    
    else
        parent->setLeft(newNode);
}

template <typename T>
BinaryTreeNode<T>* BinarySearchTree<T>::search(const T& value) const
{
    BinaryTreeNode<T>* current = root;

    while (current)
    {
        if (value == current->key())
            return current;
        
        if (value > current->key())
            current = current->right();
        
        else
            current = current->left();
    }

    return nullptr;
}

template <typename T>
bool BinarySearchTree<T>::remove(const T& value)
{
    BinaryTreeNode<T>* current = root;
    BinaryTreeNode<T>* parent = nullptr;

    // Step 1: Search for value
    bool found = false;
    while (current)
    {
        if (value == current->key())
        {
            found = true;
            break;
        }

        parent = current;

        if (value >= current->key())
            current = current->right();
        
        else
            current = current->left();
    }

    if (!found)
        return false;
    
    // Step 2: Differentiate between different cases

    // Case 1: Node is a leaf
    if (current->isLeaf())
    {
        // Case 1.1: Is leaf AND root
        if (current == root)
            root = nullptr;
        
        // Case 1.2: Is leaf but not root
        else
        {
            if (current->key() >= parent->key())
                parent->setRight(nullptr);
            
            else
                parent->setLeft(nullptr);
        }

        delete current;
        return true;
    }

    // Case 2: Node has only one child
    // Case 2.1: Child is on right
    else if (current->left() == nullptr)
    {
        // Case 2.1.1: Node doesn't have a parent (is root)
        if (current == root)
            root = current->right();
        
        // Case 2.1.2: Node has a parent
        else
        {
            if (current->key() >= parent->key())
                parent->setRight(current->right());
            
            else
                parent->setLeft(current->right());
        }

        delete current;
        return true;
    }

    // Case 2.2: Child is on left
    else if (current->right() == nullptr)
    {
        // Case 2.2.1: Node doesn't have a parent (is root)
        if (current == root)
            root = current->left();
        
        // Case 2.2.2: Node has a parent
        else
        {
            if (current->key() >= parent->key())
                parent->setRight(current->left());
            
            else
                parent->setLeft(current->left());
        }

        delete current;
        return true;
    }

    // Case 3: Node has 2 children
    else
    {
        BinaryTreeNode<T>* p = current->left();
        BinaryTreeNode<T>* parent = current;

        while (p->right())
        {
            parent = p;
            p = p->right();
        }

        if (p->key() >= parent->key())
            parent->setRight(p->left());
        
        else
            parent->setLeft(p->left());
        
        current->setKey(p->key());

        delete p;
        return true;
    }
}

template <typename T>
void BinarySearchTree<T>::inorder() const
{
    inorder(root);
}

template <typename T>
void BinarySearchTree<T>::inorder(BinaryTreeNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    inorder(p->left());
    std::cout << " " << p->key() << " ";
    inorder(p->right());
}

template <typename T>
void BinarySearchTree<T>::preorder() const
{
    preorder(root);
}

template <typename T>
void BinarySearchTree<T>::preorder(BinaryTreeNode<T>* p) const
{
    if (p == nullptr)
        return;

    std::cout << " " << p->key() << " ";
    preorder(p->left());
    preorder(p->right());
}

template <typename T>
void BinarySearchTree<T>::postorder() const
{
    postorder(root);
}

template <typename T>
void BinarySearchTree<T>::postorder(BinaryTreeNode<T>* p) const
{
    if (p == nullptr)
        return;

    postorder(p->left());
    postorder(p->right());
    std::cout << " " << p->key() << " ";
}
