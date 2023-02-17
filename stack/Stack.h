#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template<typename T>
class Stack
{
    public:
        Stack(unsigned int);
        ~Stack();
        bool isEmpty() const;
        bool isFull() const;
        int getTopIndex() const;
        const T& getTopItem() const;
        void push(const T&);
        T pop();

    private:
        T* stack;
        unsigned int capacity;
        int topIndex = -1;
};

template<typename T>
Stack<T>::Stack(unsigned int size)
{
    if (!size)
    {
        throw std::runtime_error("Stack capacity cannot be zero!");
    }

    capacity = size;
    stack = new T[capacity];
}

template<typename T>
Stack<T>::~Stack()
{
    delete [] stack;
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return topIndex == -1;
}

template<typename T>
bool Stack<T>::isFull() const
{
    return topIndex == capacity - 1;
}

template<typename T>
int Stack<T>::getTopIndex() const
{
    return topIndex;
}

template<typename T>
const T& Stack<T>::getTopItem() const
{
    return stack[topIndex];
}

template<typename T>
void Stack<T>::push(const T& data)
{
    if (isFull())
    {
        throw std::runtime_error("Stack is full!");
    }

    topIndex += 1;
    stack[topIndex] = data;
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw std::runtime_error("Stack is empty!");
    }

    T temp = stack[topIndex];
    stack[topIndex].~T();
    topIndex -= 1;

    return temp;
}

#endif // STACK_H_INCLUDED
