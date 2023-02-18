#include "LinkedList.h"

template <typename T>
class LinkedStack
{
    public:
        LinkedStack();
        ~LinkedStack();
        bool isEmpty() const;
        void push(const T&);
        void pop();
        const T& top() const;
    
    private:
        LinkedList<T> stack;
};

template <typename T>
LinkedStack<T>::LinkedStack()
{
    // Empty body
}

template <typename T>
LinkedStack<T>::~LinkedStack()
{
    while (!stack.isEmpty())
    {
        stack.delHead();
    }
}

template <typename T>
bool LinkedStack<T>::isEmpty() const
{
    return stack.isEmpty();
}

template <typename T>
void LinkedStack<T>::push(const T& data)
{
    stack.addHead(data);
}

template <typename T>
void LinkedStack<T>::pop()
{
    stack.delHead();
}

template <typename T>
const T& LinkedStack<T>::top() const
{
    return stack.getHead();
}
