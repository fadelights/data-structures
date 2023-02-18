#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include <stdexcept>

template<typename T>
class Queue
{
    public:
        Queue(unsigned int);
        ~Queue();
        bool isEmpty() const;
        bool isFull() const;
        const T& front() const;
        const T& rear() const;
        void enq(const T&);
        T deq();

    private:
        unsigned int circularAdd(unsigned int) const;
        unsigned int circularSub(unsigned int) const;
        unsigned int size;
        T* queue;
        unsigned int frontIndex = 0;
        unsigned int rearIndex = 0;
};

template<typename T>
unsigned int Queue<T>::circularAdd(unsigned int index) const
{
    return (index + 1) % size;
}

template<typename T>
unsigned int Queue<T>::circularSub(unsigned int index) const
{
    long int temp = (index - 1) % size;

    if (temp >= 0)
        return temp;
    else
        return temp + size;
}

template<typename T>
Queue<T>::Queue(unsigned int sizeOfQueue)
{
    if (sizeOfQueue < 1)
        throw std::runtime_error("Queue size cannot be zero!");

    size = sizeOfQueue + 1;
    queue = new T[size];
}

template<typename T>
Queue<T>::~Queue()
{
    delete [] queue;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
    return frontIndex == rearIndex;
}

template<typename T>
bool Queue<T>::isFull() const
{
    return frontIndex == circularAdd(rearIndex);
}

template<typename T>
const T& Queue<T>::front() const
{
    if (isEmpty())
        throw std::runtime_error("Can't read `front` of empty queue!");

    return queue[frontIndex];
}

template<typename T>
const T& Queue<T>::rear() const
{
    if (isEmpty())
        throw std::runtime_error("Can't read `rear` of empty queue!");

    return queue[circularSub(rearIndex)];
}

template<typename T>
void Queue<T>::enq(const T& data)
{
    if (isFull())
        throw std::runtime_error("Queue is full!");

    queue[rearIndex] = data;
    rearIndex = circularAdd(rearIndex);
}

template<typename T>
T Queue<T>::deq()
{
    if (isEmpty())
        throw std::runtime_error("Queue is empty!");

    T temp = queue[frontIndex];
    queue[frontIndex].~T();
    frontIndex = circularAdd(frontIndex);

    return temp;
}

#endif // QUEUE_H_INCLUDED
