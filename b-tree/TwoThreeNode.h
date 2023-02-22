#ifndef TWOTHREENODE_H_INCLUDED
#define TWOTHREENODE_H_INCLUDED

#include <stdexcept>

template <typename T>
class TwoThreeNode
{
    public:
        TwoThreeNode();
        bool isLeaf() const;
        bool isFull() const;
        void shrink();
        void insertKey(T, TwoThreeNode<T>* = nullptr);

        void setKey(unsigned int, T);
        void setKeyCount(unsigned int);
        void setChild(unsigned int, TwoThreeNode<T>*);
        void setParent(TwoThreeNode<T>*);
        
        T getKey(unsigned int) const;
        TwoThreeNode<T>* getChild(unsigned int) const;
        TwoThreeNode<T>* getParent() const;
    
    private:
        T key[2];
        unsigned int keyCount;
        TwoThreeNode<T>* child[3];
        TwoThreeNode<T>* parent;
};

template <typename T>
TwoThreeNode<T>::TwoThreeNode()
{
    keyCount = 0;
    child[0] = child[1] = child[2] = parent = nullptr;
}

template <typename T>
bool TwoThreeNode<T>::isLeaf() const
{
    return !child[0] && !child[1] && !child[2];
}

template <typename T>
bool TwoThreeNode<T>::isFull() const
{
    return keyCount == 2;
}

template <typename T>
void TwoThreeNode<T>::shrink()
{
    if (isFull())
    {
        setChild(2, nullptr);
        setKeyCount(1);
    }
}

template <typename T>
void TwoThreeNode<T>::insertKey(T value, TwoThreeNode<T>* newChild)
{
    if (isFull())
        throw std::out_of_range("insertion into a full node");
    
    // if value must be placed in the first spot of node
    if (value < getKey(0))
    {
        // shift old key forward
        setKey(1, getKey(0));
        setChild(2, getChild(1));

        // place value
        setKey(0, value);
        setChild(1, newChild);
    }

    // if value must be placed in the second spot of node
    else
    {
        // second spot is already empty
        setKey(1, value);
        setChild(2, newChild);
    }
}

template <typename T>
void TwoThreeNode<T>::setKey(unsigned int index, T value)
{
    if (index > 1 || (index == 1 && keyCount == 0))
        throw std::invalid_argument("invalid setKey index");
    
    key[index] = value;
    if (index == keyCount)
        keyCount++;
}

template <typename T>
void TwoThreeNode<T>::setKeyCount(unsigned int n)
{
    if (n > 2)
        throw std::invalid_argument("invalid setKeyCount index, must be 0, 1 or 2");
    
    keyCount = n;
}

template <typename T>
void TwoThreeNode<T>::setChild(unsigned int index, TwoThreeNode<T>* p)
{
    // valid child indices are 0, 1, 2
    if (index > 2)
        throw std::invalid_argument("invalid setChild index");
    
    if (p != nullptr)
    {
        // if node already contains an empty spot and entered index is 2
        if (index == 2 && keyCount < 2)
            throw std::invalid_argument("invalid setChild index");
        
        // if node is already empty, it cannot have a child
        if (index == 1 && keyCount < 1) // if (keyCount == 0)
            throw std::invalid_argument("invalid setChild index");
    }

    child[index] = p;
    if (p)
        p->setParent(this);
}

template <typename T>
void TwoThreeNode<T>::setParent(TwoThreeNode<T>* p)
{
    parent = p;
}

template <typename T>
T TwoThreeNode<T>::getKey(unsigned int index) const
{
    if (index >= keyCount)
        throw std::invalid_argument("invalid getKey index");
    
    return key[index];
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getChild(unsigned int index) const
{
    if (index > keyCount)
        throw std::invalid_argument("invalid getChild index");
    
    return child[index];
}

template <typename T>
TwoThreeNode<T>* TwoThreeNode<T>::getParent() const
{
    return parent;
}

#endif // TWOTHREENODE_H_INCLUDED
