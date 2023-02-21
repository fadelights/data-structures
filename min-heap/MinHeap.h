#include <vector>
#include <utility>
#include <limits>
#include <iostream>

template <typename T>
class MinHeap
{
    public:
        MinHeap(int = 100);
        MinHeap(T*, int);
        ~MinHeap();

        bool isEmpty();
        void buildMinHeap();
        T min();
        T extractMin();
        void decreaseKey(int, T);
        void insert(T);
        void sort();
        void show(int = 0);

    private:
        int parent(int);
        int left(int);
        int right(int);
        void minHeapify(int);

        std::vector<T> heap;
        int size;
        int capacity;
};

template <typename T>
MinHeap<T>::MinHeap(int capacity)
    : capacity{capacity + 1}
    , size{0}
    , heap{capacity + 1}
{
    // Empty body
}

template <typename T>
MinHeap<T>::MinHeap(T* array, int capacity)
    : capacity{capacity + 1}
    , size{capacity}
{
    heap.push_back(0); // the first element of a heap is always a dummy element
    for (int i{0}; i < capacity; i++)
    {
        heap.push_back(array[i]);
    }

    buildMinHeap();
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    // Uses vector's destructor
}

template <typename T>
int MinHeap<T>::parent(int i)
{
    return i / 2;
}

template <typename T>
int MinHeap<T>::left(int i)
{
    return 2 * i;
}

template <typename T>
int MinHeap<T>::right(int i)
{
    return 2 * i + 1;
}

template <typename T>
void MinHeap<T>::minHeapify(int i)
{
    int l_index{left(i)};
    int r_index{right(i)};
    int min_index{i}; // between current, left and right indices

    if (l_index <= size && heap[l_index] < heap[min_index])
        min_index = l_index;

    if (r_index <= size && heap[r_index] < heap[min_index])
        min_index = r_index;

    // switch values if necessary
    if (i == min_index)
        return;

    else
    {
        std::swap(heap[i], heap[min_index]);
        minHeapify(min_index);
    }
}

template <typename T>
bool MinHeap<T>::isEmpty()
{
    return size == 0;
}

template <typename T>
void MinHeap<T>::buildMinHeap()
{
    for (int i{size / 2}; i > 0; i--)
        minHeapify(i);
}

template <typename T>
T MinHeap<T>::min()
{
    if (isEmpty())
        throw std::runtime_error("Reading minimum of empty heap.");
    
    return heap[1];
}

template <typename T>
T MinHeap<T>::extractMin()
{
    if (isEmpty())
        throw std::runtime_error("Reading minimum of empty heap.");
    
    T minimum{heap[1]};
    heap[1] = heap[size];
    size--;
    minHeapify(1);

    return minimum;
}

template <typename T>
void MinHeap<T>::decreaseKey(int i, T key)
{
    if (i < 1 || i > size || heap[i] <= key)
        return;
    
    heap[i] = key;

    while (i > 1 && heap[i] < heap[parent(i)])
    {
        std::swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

template <typename T>
void MinHeap<T>::insert(T key)
{
    size++;
    if (size > capacity)
    {
        capacity *= 2;
        heap.resize(capacity);
    }

    heap[size] = std::numeric_limits<T>::max();
    decreaseKey(size, key);
}

template <typename T>
void MinHeap<T>::sort()
{
    while (size > 1)
    {
        std::swap(heap[1], heap[size]);
        size--;
        minHeapify(1);
    }
}

template <typename T>
void MinHeap<T>::show(int n)
{
    if (n == 0)
        n = size;

    for (int i{1}; i <= n; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
}
