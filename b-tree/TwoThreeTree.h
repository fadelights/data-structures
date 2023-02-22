#ifndef TWOTHREETREE_H_INCLUDED
#define TWOTHREETREE_H_INCLUDED

#include <iostream>
#include "TwoThreeNode.h"

template <typename T>
class TwoThreeTree
{
    public:
        TwoThreeTree();
        bool isEmpty();
        void insert(T);
        void sortedorder();
        void preorder();
    
    private:
        TwoThreeNode<T>* root;
        void split(TwoThreeNode<T>*, T, TwoThreeNode<T>*);
        void sortedorder(TwoThreeNode<T>*);
        void preorder(TwoThreeNode<T>*);
};

template <typename T>
TwoThreeTree<T>::TwoThreeTree()
    : root(nullptr)
{
    // empty body
}

template <typename T>
bool TwoThreeTree<T>::isEmpty()
{
    return root == nullptr;
}

template <typename T>
void TwoThreeTree<T>::insert(T value)
{
    // special case: empty tree
    if (isEmpty())
    {
        root = new TwoThreeNode<T>;
        root->setKey(0, value);
        return;
    }
    
    // find the leaf p, where value should be inserted
    TwoThreeNode<T>* p = root;
    while (!p->isLeaf())
    {
        if (value < p->getKey(0))
            p = p->getChild(0);
        
        else if (!p->isFull() || (p->isFull() && value < p->getKey(1)))
            p = p->getChild(1);
        
        else
            p = p->getChild(2);
    }

    // insert value into p
    if (p->isFull())
        // case 1: p is full
        split(p, value, nullptr);
    
    else
        // case 2: p is not full
        p->insertKey(value);
}

template <typename T>
void TwoThreeTree<T>::split(TwoThreeNode<T>* p, T value, TwoThreeNode<T>* newChild)
{
    // create a new node and set parents
    TwoThreeNode<T>* newNode = new TwoThreeNode<T>;
    TwoThreeNode<T>* parent = (p == root ? new TwoThreeNode<T> : p->getParent());

    // calculate order of the keys
    T min = p->getKey(0), mid = p->getKey(1), max;
    if (value < min)
    {
        max = mid;
        mid = min;
        min = value;
    }

    else if (value < mid)
    {
        max = mid;
        mid = value;
    }

    else
    {
        max = value;
    }

    // split
    // set keys and children of p and newNode
    p->setKey(0, min);
    newNode->setKey(0, max);
    if (!p->isLeaf())
    {
        if (value == max)
        {
            newNode->setChild(0, p->getChild(2));
            newNode->setChild(1, newChild);
        }

        else if (value == mid)
        {
            newNode->setChild(1, p->getChild(2));
            newNode->setChild(0, newChild);
        }

        else // if (value == min)
        {
            newNode->setChild(1, p->getChild(2));
            newNode->setChild(0, p->getChild(1));
            p->setChild(1, newChild);
        }
    }

    p->shrink();

    // recursively insert middle key into the parent
    if (p == root) // special case
    {
        parent->setKey(0, mid);
        parent->setChild(0, p);
        parent->setChild(1, newNode);
        root = parent;
    }

    else if (parent->isFull())
    {
        split(parent, mid, newNode);
    }

    else // parent is not full
    {
        parent->insertKey(mid, newNode);
    }
}

template <typename T>
void TwoThreeTree<T>::sortedorder()
{
    sortedorder(root);
}

template <typename T>
void TwoThreeTree<T>::sortedorder(TwoThreeNode<T>* p)
{
    if (!p->isLeaf())
        sortedorder(p->getChild(0));
    
    std::cout << p->getKey(0) << " ";

    if (!p->isLeaf())
        sortedorder(p->getChild(1));
    
    if (p->isFull())
    {
        std::cout << p->getKey(1) << " ";

        if (!p->isLeaf())
            sortedorder(p->getChild(2));
    }
}

template <typename T>
void TwoThreeTree<T>::preorder()
{
    preorder(root);
}

template <typename T>
void TwoThreeTree<T>::preorder(TwoThreeNode<T>* p)
{
    std::cout << "[" << p->getKey(0);

    if (p->isFull())
        std::cout << "-" << p->getKey(1);
    
    std::cout << "] ";

    if (!p->isLeaf())
    {
        preorder(p->getChild(0));
        preorder(p->getChild(1));

        if (p->isFull())
            preorder(p->getChild(2));
    }
}

#endif // TWOTHREETREE_H_INCLUDED
