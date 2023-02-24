#ifndef AVLNODE_H_INCLUDED
#define AVLNODE_H_INCLUDED

template <typename T> class AVLTree;

template <typename T>
class AVLNode
{
    friend class AVLTree<T>;

    public:
        AVLNode(T value)
            : key{value}
            , left{nullptr}
            , right{nullptr}
            , balancefactor{0}
            {
                // Empty body
            }
    
    private:
        T key;
        int balancefactor;
        AVLNode<T>* left;
        AVLNode<T>* right;
};

#endif // AVLNODE_H_INCLUDED
