#include <iostream>

template <typename T>
class LinkedList;

template <typename T>
class Node
{
    private:
        T data;
        Node<T>* next;
        friend class LinkedList<T>;
};

template <typename T>
class LinkedList
{
    public:
        LinkedList();
        ~LinkedList();
        bool isEmpty() const;
        const T& getHead() const;
        void addHead(const T&);
        void delHead();
        void sortedInsert(const T&);
        void print() const;
    
    private:
        Node<T>* head;
};

template <typename T>
LinkedList<T>::LinkedList()
    : head(NULL)
    {
        // Empty body
    }

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (!isEmpty())
    {
        delHead();
    }
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return head == NULL;
}

template <typename T>
const T& LinkedList<T>::getHead() const
{
    if (isEmpty())
    {
        // throw std::runtime_error("Head of empty list.");
        static int zero{0};
        return zero;
    }
    
    return head->data;
}

template <typename T>
void LinkedList<T>::addHead(const T& data)
{
    Node<T>* p = new Node<T>;
    p->data = data;
    p->next = head;
    head = p;
}

template <typename T>
void LinkedList<T>::delHead()
{
    if (isEmpty())
        // throw std::runtime_error("List is empty.");
        return;
    
    Node<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void LinkedList<T>::sortedInsert(const T& data)
{
    Node<T>* newNodePointer = new Node<T>;
    Node<T>* movingPointer = head;
    newNodePointer->data = data;
    
    if (isEmpty() || newNodePointer->data < head->data)
    {
        newNodePointer->next = head;
        head = newNodePointer;
    }

    else
    {
        while (movingPointer->next != NULL && newNodePointer->data > movingPointer->next->data)
        {
            movingPointer = movingPointer->next; 
        }
        newNodePointer->next = movingPointer->next;
        movingPointer->next = newNodePointer;
    }
}

template <typename T>
void LinkedList<T>::print() const
{
    Node<T>* p = head;
    while (p != NULL)
    {
        std::cout << p->data << ", ";
        p = p->next;
    }

    std::cout << std::endl;
}
