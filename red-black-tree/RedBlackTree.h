#ifndef REDBLACKTREE_H_INCLUDED
#define REDBLACKTREE_H_INCLUDED

#include <iostream>
#include "RedBlackNode.h"

template <typename T>
class RedBlackTree
{
    public:
        RedBlackTree();
        bool isEmpty() const;
        void insert(const T&);
        void inorder() const;
        void preorder() const;
    
    private:
        void bstinsert(RedBlackNode<T>*);
        RedBlackNode<T>* uncle(RedBlackNode<T>*) const;
        void fixPossibleViolation(RedBlackNode<T>*);
        void recolor(RedBlackNode<T>*);
        void rotateLeft(RedBlackNode<T>*);
        void rotateRight(RedBlackNode<T>*);

        void inorder(RedBlackNode<T>*) const;
        void preorder(RedBlackNode<T>*) const;

        RedBlackNode<T>* root;
};

template <typename T>
RedBlackTree<T>::RedBlackTree()
    : root{nullptr}
{

}

template <typename T>
bool RedBlackTree<T>::isEmpty() const
{
    return root == nullptr;
}

template <typename T>
void RedBlackTree<T>::bstinsert(RedBlackNode<T>* node)
{
    if (isEmpty())
    {
        root = node;
        return;
    }

    RedBlackNode<T> *p{root}, *parent_p{nullptr};
    while (p)
    {
        if (node->key < p->key)
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

    node->parent = parent_p;
    if (node->key < parent_p->key)
        parent_p->left = node;
    
    else
        parent_p->right = node;
}

template <typename T>
RedBlackNode<T>* RedBlackTree<T>::uncle(RedBlackNode<T>* x) const
{
    if (x == nullptr || x->parent == nullptr || x->parent->parent == nullptr)
        throw std::runtime_error("wrong uncle");

    if (x->parent == x->parent->parent->left)
        return x->parent->parent->right;
    
    else
        return x->parent->parent->left;
}

template <typename T>
void RedBlackTree<T>::fixPossibleViolation(RedBlackNode<T>* x)
{
    // black nodes are OK!
    if (x->color == BLACK)
        return;

    // RB1:
    if (x == root)
    {
        x->color = BLACK;
        return;
    }

    // nodes with black parents are OK!
    RedBlackNode<T>* parent = x->parent;
    if (parent->color == BLACK)
        return;
    
    // recolor
    RedBlackNode<T>* g{parent->parent};
    RedBlackNode<T>* u{uncle(x)};

    if (u != nullptr && u->color == RED)
    {
        recolor(g);
        fixPossibleViolation(g);
        return;
    }
    
    // rotate
    if (x == parent->left && parent == g->left)
    {
        rotateRight(g);
    }

    else if (x == parent->right && parent == g->left)
    {
        rotateLeft(parent);
        rotateRight(g);
    }

    else if (x == parent->right && parent == g->right)
    {
        rotateLeft(g);
    }

    else if (x == parent->left && parent == g->right)
    {
        rotateRight(parent);
        rotateLeft(g);
    }

    g->color = RED;
    g->parent->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::recolor(RedBlackNode<T>* grandparent)
{
    if (grandparent->color == RED ||
        grandparent->left->color == BLACK ||
        grandparent->right->color == BLACK)
    {
        throw std::logic_error("wrong recolor");
    }
    
    grandparent->color = RED;
    grandparent->left->color = BLACK;
    grandparent->right->color = BLACK;
}

template <typename T>
void RedBlackTree<T>::rotateLeft(RedBlackNode<T>* p)
{
    RedBlackNode<T>* right_child{p->right};

    p->right = right_child->left;
    if (p->right != nullptr)
        p->right->parent = p;
    
    right_child->parent = p->parent;
    if (p->parent == nullptr)
        root = right_child;
    
    else if (p == p->parent->left)
        p->parent->left = right_child;
    
    else
        p->parent->right = right_child;
    
    right_child->left = p;
    p->parent = right_child;
}

template <typename T>
void RedBlackTree<T>::rotateRight(RedBlackNode<T>* p)
{
    RedBlackNode<T>* left_child{p->left};

    p->left = left_child->right;
    if (p->left != nullptr)
        p->left->parent = p;
    
    left_child->parent = p->parent;
    if (p->parent == nullptr)
        root = left_child;
    
    else if (p == p->parent->left)
        p->parent->left = left_child;
    
    else
        p->parent->right = left_child;
    
    left_child->right = p;
    p->parent = left_child;
}

template <typename T>
void RedBlackTree<T>::insert(const T& value)
{
    RedBlackNode<T>* newNode{new RedBlackNode<T>(value)};

    bstinsert(newNode);
    fixPossibleViolation(newNode);
}

template <typename T>
void RedBlackTree<T>::inorder(RedBlackNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    inorder(p->left);
    std::cout << "(" << p->key << ")-" << "(" << (p->color == BLACK ? "BLACK": "RED") << ") " << " ";
    inorder(p->right);
}

template <typename T>
void RedBlackTree<T>::inorder() const
{
    inorder(root);
}

template <typename T>
void RedBlackTree<T>::preorder(RedBlackNode<T>* p) const
{
    if (p == nullptr)
        return;
    
    std::cout << "(" << p->key << ")-" << "(" << (p->color == BLACK ? "BLACK": "RED") << ") " << " ";
    preorder(p->left);
    preorder(p->right);
}

template <typename T>
void RedBlackTree<T>::preorder() const
{
    preorder(root);
}

#endif // REDBLACKTREE_H_INCLUDED
