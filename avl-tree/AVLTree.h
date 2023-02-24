#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include <iostream>
#include "AVLNode.h"

template <typename T>
class AVLTree
{
    public:
        AVLTree();
        void insert(T);
        void inorder() const;
        void preorder() const;
        void postorder() const;
        bool isEmpty() const;
    
    private:
        void adjust(AVLNode<T>*, AVLNode<T>*);
        AVLNode<T>* rotate_ll(AVLNode<T>*);
        AVLNode<T>* rotate_lr(AVLNode<T>*);
        AVLNode<T>* rotate_rl(AVLNode<T>*);
        AVLNode<T>* rotate_rr(AVLNode<T>*);

        void inorder(AVLNode<T>*) const;
        void preorder(AVLNode<T>*) const;
        void postorder(AVLNode<T>*) const;

        AVLNode<T>* root;
};

template <typename T>
AVLTree<T>::AVLTree()
    : root{nullptr}
{

}

template <typename T>
void AVLTree<T>::insert(T value)
{
    // Special case: Initial insertion to an empty tree
    if (isEmpty())
    {
        root = new AVLNode<T>(value);
        return;
    }

    // Step 1: Find A and insert new node
    AVLNode<T>* p{root};
    AVLNode<T>* parent_p{nullptr};
    AVLNode<T>* A{root};
    AVLNode<T>* parent_A{nullptr};

    while (p)
    {
        if (p->balancefactor)
        {
            A = p;
            parent_A = parent_p;
        }

        if (value < p->key)
        {
            parent_p = p;
            p = p->left;
        }

        else
        {
            parent_p = p;
            p = p->right;
        }
    }

    AVLNode<T>* newNode = new AVLNode<T>(value);
    if (value < parent_p->key)
        parent_p->left = newNode;
    
    else
        parent_p->right = newNode;

    // Step 2: Update balance factors from A to new node's parent
    AVLNode<T>* q{A};
    while (q != newNode)
    {
        if (value < q->key)
        {
            q->balancefactor += 1;
            q = q->left;
        }

        else
        {
            q->balancefactor -= 1;
            q = q->right;
        }
    }

    // Step 3: Check if A's bf is still valid and adjust if necessary
    if (A->balancefactor == 2 || A->balancefactor == -2)
    {
        adjust(A, parent_A);
    } 
}

template <typename T>
void AVLTree<T>::adjust(AVLNode<T>* a, AVLNode<T>* parent_a)
{
    AVLNode<T>* sub_root;

    if (a->balancefactor == 2 && a->left->balancefactor == 1)
        sub_root = rotate_ll(a);
    
    else if (a->balancefactor == 2 && a->left->balancefactor == -1)
        sub_root = rotate_lr(a);
    
    else if (a->balancefactor == -2 && a->right->balancefactor == 1)
        sub_root = rotate_rl(a);
    
    else
        sub_root = rotate_rr(a);
    
    if (!parent_a) // special case: a is root
        root = sub_root;
    
    else if (a == parent_a->left)
        parent_a->left = sub_root;

    else
        parent_a->right = sub_root; 
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotate_ll(AVLNode<T>* a)
{
    AVLNode<T>* b{a->left};

    a->left = b->right;
    b->right = a;

    a->balancefactor = 0;
    b->balancefactor = 0;

    return b;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotate_lr(AVLNode<T>* a)
{
    AVLNode<T>* b{a->left};
    AVLNode<T>* c{b->right};

    a->left = c->right;
    b->right = c->left;

    c->right = a;
    c->left = b;

    switch (c->balancefactor)
    {
        case -1:
            a->balancefactor = 0;
            b->balancefactor = 1;
            break;

        case 0:
            a->balancefactor = 0; 
            b->balancefactor = 0;
            break;
        
        case 1:
            a->balancefactor = -1;
            b->balancefactor = 0;
            break;
    }

    c->balancefactor = 0;

    return c;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotate_rl(AVLNode<T>* a)
{
    AVLNode<T>* b{a->right};
    AVLNode<T>* c{b->left};

    a->right = c->left;
    b->left = c->right;

    c->left = a;
    c->right = b;

    switch (c->balancefactor)
    {
        case -1:
            a->balancefactor = 1;
            b->balancefactor = 0;
            break;

        case 0:
            a->balancefactor = 0; 
            b->balancefactor = 0;
            break;
        
        case 1:
            a->balancefactor = 0;
            b->balancefactor = -1;
            break;
    }

    c->balancefactor = 0;

    return c;
}

template <typename T>
AVLNode<T>* AVLTree<T>::rotate_rr(AVLNode<T>* a)
{
    AVLNode<T>* b{a->right};

    a->right = b->left;
    b->left = a;

    a->balancefactor = 0;
    b->balancefactor = 0;

    return b;
}

template <typename T>
void AVLTree<T>::inorder() const
{
    inorder(root);
}

template <typename T>
void AVLTree<T>::inorder(AVLNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    inorder(p->left);
    std::cout << " " << p->key << " ";
    inorder(p->right);
}

template <typename T>
void AVLTree<T>::preorder() const
{
    preorder(root);
}

template <typename T>
void AVLTree<T>::preorder(AVLNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    std::cout << " " << p->key << " ";
    preorder(p->left);
    preorder(p->right);
}

template <typename T>
void AVLTree<T>::postorder() const
{
    postorder(root);
}

template <typename T>
void AVLTree<T>::postorder(AVLNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    postorder(p->left);
    postorder(p->right);
    std::cout << " " << p->key << " ";
}

template <typename T>
bool AVLTree<T>::isEmpty() const
{
    return root == nullptr;
}

#endif // AVLTREE_H_INCLUDED
