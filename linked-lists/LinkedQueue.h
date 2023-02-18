#include "DoubleLinkedList.h"

template <typename T>
class LinkedQueue : public DoubleLinkedList<T>
{
    public:
        LinkedQueue();
        ~LinkedQueue();
        void enq(const T&);
        void deq();
        const T& start() const;
        const T& end() const;
};

template <typename T>
LinkedQueue<T>::LinkedQueue()
    : DoubleLinkedList<T>()
{
    // empty body
}

template <typename T>
LinkedQueue<T>::~LinkedQueue()
{
    // empty (will use parent's destructor)
}

template <typename T>
void LinkedQueue<T>::enq(const T& data)
{
    DoubleLinkedList<T>::addFirst(data);
}

template <typename T>
void LinkedQueue<T>::deq()
{
    if (DoubleLinkedList<T>::isEmpty())
        throw std::runtime_error("Cannot dequeue empty queue.");
    
    DoubleLinkedList<T>::delLast();
}

template <typename T>
const T& LinkedQueue<T>::start() const
{
    return DoubleLinkedList<T>::getLast();
}

template <typename T>
const T& LinkedQueue<T>::end() const
{
    return DoubleLinkedList<T>::getFirst();
}
