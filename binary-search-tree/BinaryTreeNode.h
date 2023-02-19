template <typename T>
class BinaryTreeNode
{
    public:
        BinaryTreeNode(T = 0);

        T key() const;
        BinaryTreeNode<T>* left() const;
        BinaryTreeNode<T>* right() const;

        bool isLeaf() const;

        void setKey(T);
        void setLeft(BinaryTreeNode<T>*);
        void setRight(BinaryTreeNode<T>*);

    private:
        T _key;
        BinaryTreeNode<T>* _left;
        BinaryTreeNode<T>* _right;
};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T value)
{
    setKey(value);
    setLeft(nullptr);
    setRight(nullptr);
}

template <typename T>
T BinaryTreeNode<T>::key() const
{
    return _key;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::left() const
{
    return _left;
}

template <typename T>
BinaryTreeNode<T>* BinaryTreeNode<T>::right() const
{
    return _right;
}

template <typename T>
bool BinaryTreeNode<T>::isLeaf() const
{
    return _left == nullptr && _right == nullptr;
}

template <typename T>
void BinaryTreeNode<T>::setKey(T value)
{
    _key = value;
}

template <typename T>
void BinaryTreeNode<T>::setLeft(BinaryTreeNode<T>* p)
{
    _left = p;
}

template <typename T>
void BinaryTreeNode<T>::setRight(BinaryTreeNode<T>* p)
{
    _right = p;
}
