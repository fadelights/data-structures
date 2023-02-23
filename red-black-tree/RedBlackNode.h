#ifndef REDBLACKNODE_H_INCLUDED
#define REDBLACKNODE_H_INCLUDED

template <typename T>
class RedBlackTree;

enum RBColor {RED, BLACK};

template <typename T>
class RedBlackNode
{
    friend class RedBlackTree<T>;

    public:
        RedBlackNode(T value)
        {
            key = value;
            color = RED;
            left = right = parent = nullptr;
        }
    
    private:
        T key;
        int color;
        RedBlackNode<T>* left;
        RedBlackNode<T>* right;
        RedBlackNode<T>* parent;
};

#endif // REDBLACKNODE_H_INCLUDED
