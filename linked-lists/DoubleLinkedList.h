#include <iostream>

template <typename T>
class DoubleLinkedList;

template <typename T>
class Node
{
    public:
        T data;
        Node<T>* next;
        Node<T>* prev;
        friend class DoubleLinkedList<T>;
};

template <typename T>
class DoubleLinkedList
{
    public:
        DoubleLinkedList();
        ~DoubleLinkedList();
        bool isEmpty() const;
        const T& getFirst() const;
        const T& getLast() const;
        void addFirst(const T&);
        void addLast(const T&);
        void delFirst();
        void delLast();
        void insert(unsigned int, const T&); // todo
        void print() const;

    private:
        Node<T>* head = new Node<T>;
        Node<T>* tail = new Node<T>;
};

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
    head->prev = NULL;
    head->next = tail;
    tail->prev = head;
    tail->next = NULL;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (!isEmpty())
    {
        delLast();
    }
}

template <typename T>
bool DoubleLinkedList<T>::isEmpty() const
{
    return head->next == tail;
}

template <typename T>
const T& DoubleLinkedList<T>::getFirst() const
{
    return head->next->data;
}

template <typename T>
const T& DoubleLinkedList<T>::getLast() const
{
    return tail->prev->data;
}

template <typename T>
void DoubleLinkedList<T>::addFirst(const T& data)
{
    Node<T>* p = new Node<T>;
    p->data = data;
    p->next = head->next;
    p->prev = head;

    head->next->prev = p;
    head->next = p;
}

template <typename T>
void DoubleLinkedList<T>::addLast(const T& data)
{
    Node<T>* p = new Node<T>;
    p->data = data;
    p->next = tail;
    p->prev = tail->prev;

    tail->prev->next = p;
    tail->prev = p;
}

template <typename T>
void DoubleLinkedList<T>::delFirst()
{
    if (isEmpty())
        throw std::runtime_error("Cannot delete from head of empty list.");
    
    Node<T>* temp = head->next;

    head->next = head->next->next;
    head->next->prev = head;

    delete temp;
}

template <typename T>
void DoubleLinkedList<T>::delLast()
{
    if (isEmpty())
        throw std::runtime_error("Cannot delete from tail of empty list.");
    
    Node<T>* temp = tail->prev;

    tail->prev = tail->prev->prev;
    tail->prev->next = tail;

    delete temp;
}

template <typename T>
void DoubleLinkedList<T>::print() const
{
    Node<T>* temp = head;
    while (temp->next != tail)
    {
        std::cout << temp->next->data << ", ";
        temp = temp->next;
    }

    std::cout << std::endl;
}
