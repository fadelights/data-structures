#include <cstddef>

template <typename T>
class SkipNode
{
    public:
        SkipNode(T);
        // ~SkipNode();

        // Getter methods
        T key() const;
        SkipNode<T>* after() const;
        SkipNode<T>* before() const;
        SkipNode<T>* above() const;
        SkipNode<T>* below() const;

        // Setter methods
        void setKey(T);
        void setAfter(SkipNode<T>*);
        void setBefore(SkipNode<T>*);
        void setAbove(SkipNode<T>*);
        void setBelow(SkipNode<T>*);

    private:
        T _key{0};
        SkipNode<T>* _after;
        SkipNode<T>* _before;
        SkipNode<T>* _above;
        SkipNode<T>* _below;
};

template <typename T>
SkipNode<T>::SkipNode(T value)
{
    setKey(value);
    setAfter(NULL);
    setBefore(NULL);
    setAbove(NULL);
    setBelow(NULL);
}

// template <typename T>
// SkipNode<T>::~SkipNode()
// {
//     // Empty
// }

template <typename T>
T SkipNode<T>::key() const
{
    return _key;
}

template <typename T>
SkipNode<T>* SkipNode<T>::after() const
{
    return _after;
}

template <typename T>
SkipNode<T>* SkipNode<T>::before() const
{
    return _before;
}

template <typename T>
SkipNode<T>* SkipNode<T>::above() const
{
    return _above;
}

template <typename T>
SkipNode<T>* SkipNode<T>::below() const
{
    return _below;
}

template <typename T>
void SkipNode<T>::setKey(T value)
{
    _key = value;
}

template <typename T>
void SkipNode<T>::setAfter(SkipNode<T>* p)
{
    _after = p;
}

template <typename T>
void SkipNode<T>::setBefore(SkipNode<T>* p)
{
    _before = p;
}

template <typename T>
void SkipNode<T>::setAbove(SkipNode<T>* p)
{
    _above = p;
}

template <typename T>
void SkipNode<T>::setBelow(SkipNode<T>* p)
{
    _below = p;
}
