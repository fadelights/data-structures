#include <limits>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "SkipNode.h"

template <typename T>
class SkipList
{
    public:
        SkipList();
        // ~SkipList();
        SkipNode<T>* search(T) const;
        void insert(T);
        bool remove(T);
        void print() const;

    private:
        void insertAfter(SkipNode<T>*, SkipNode<T>*);
        void addHeight();
        void subHeight(int);
        SkipNode<T>* aboveLeft(SkipNode<T>*) const;

        SkipNode<T>* head;
        SkipNode<T>* tail;
        int height{0};
};

template <typename T>
SkipList<T>::SkipList()
{
    head = new SkipNode<T>(std::numeric_limits<T>::min()); // -inf
    tail = new SkipNode<T>(std::numeric_limits<T>::max()); // +inf

    head->setAfter(tail);
    tail->setBefore(head);
}

template <typename T>
SkipNode<T>* SkipList<T>::search(T value) const
{
    SkipNode<T>* p = head;
    
    // reach maximum height 
    while (p->above())
    {
        p = p->above();
    }

    // start searching and continue until reaching bottom
    while (p->below())
    {
        p = p->below();
        while (p->after()->key() <= value)
        {
            p = p->after();
        }
    }

    // return the current location 
    // regardless of whether the search was a success 
    return p;
}

template <typename T>
void SkipList<T>::insertAfter(SkipNode<T>* u, SkipNode<T>* v)
{
    // inserts v after u
    v->setAfter(u->after());
    v->setBefore(u);

    u->after()->setBefore(v);
    u->setAfter(v);
}

template <typename T>
void SkipList<T>::addHeight()
{
    SkipNode<T>* headTop{head};
    SkipNode<T>* tailTop{tail};

    // set headTop & tailTop to point to the top of the SkipList (top of ±inf)
    while (headTop->above())
    {
        headTop = headTop->above();
        tailTop = tailTop->above();
    }

    // defining new nodes for top
    SkipNode<T>* newHeadTop = new SkipNode<T>(std::numeric_limits<T>::min());
    SkipNode<T>* newTailTop = new SkipNode<T>(std::numeric_limits<T>::max());

    // setting up new nodes
    headTop->setAbove(newHeadTop);
    tailTop->setAbove(newTailTop);

    newHeadTop->setAfter(newTailTop);
    newTailTop->setBefore(newHeadTop);

    newHeadTop->setBelow(headTop);
    newTailTop->setBelow(tailTop);

    headTop = headTop->above(); // in other words: newHeadTop
    tailTop = tailTop->above();

    height++;
}

template <typename T>
void SkipList<T>::subHeight(int h)
{
    SkipNode<T>* p{head};
    SkipNode<T>* q{tail};

    for (int i{0}; i < height - h; i++)
    {
        p = p->above();
        q = q->above();
    }

    SkipNode<T>* up_h{p->above()};
    SkipNode<T>* up_t{q->above()};

    p->setAbove(NULL);
    q->setAbove(NULL);

    SkipNode<T>* temp_h{up_h};
    SkipNode<T>* temp_t{up_t};
    while (up_h)
    {
        delete up_h;
        delete up_t;

        up_h = temp_h->above();
        up_t = temp_t->above();

        temp_h = up_h;
        temp_t = up_t;
    }

    height -= h;
}

template <typename T>
SkipNode<T>* SkipList<T>::aboveLeft(SkipNode<T>* node) const
{
    while (node->above() == NULL)
    {
        node = node->before();
    }

    return node->above();
}

template <typename T>
void SkipList<T>::insert(T value)
{
    if (height == 0)
    {
        addHeight();
    }

    SkipNode<T>* newNode = new SkipNode<T>(value);
    SkipNode<T>* prevNode = search(value);
    insertAfter(prevNode, newNode);

    // randomly increase height of newNode
    SkipNode<T>* upperNode;
    for (int i{1}; std::rand() % 2; i++)
    {
        if (i == height)
        {
            addHeight();
        }

        upperNode = new SkipNode<T>(value);
        prevNode = aboveLeft(newNode);
        insertAfter(prevNode, upperNode);
        
        newNode->setAbove(upperNode);
        upperNode->setBelow(newNode);
        newNode = upperNode;
    }
}

template <typename T>
bool SkipList<T>::remove(T value)
{
    SkipNode<T>* node = search(value);
    if (node->key() != value)
    {
        return false;
    }

    int rowsToRemove{0};

    SkipNode<T>* upperNode;
    while (node)
    {
        upperNode = node->above();

        node->before()->setAfter(node->after());
        node->after()->setBefore(node->before());

        if (node->after()->key() == std::numeric_limits<T>::max() &&
            node->before()->key() == std::numeric_limits<T>::min())
        {
            rowsToRemove++;
        }

        delete node;

        node = upperNode;
    }

    if (rowsToRemove)
    {
        subHeight(rowsToRemove);
    }

    return true;
}

template <typename T>
void SkipList<T>::print() const
{
    for (SkipNode<T>* p = head; p; p = p->above())
    {
        std::cout << std::left << std::setw(5) << "-INF";
    }
    std::cout << std::endl;

    for (SkipNode<T>* p = head->after(); p->after(); p = p->after())
    {
        for (SkipNode<T>* q = p; q; q = q->above())
        {
            std::cout << ' ' << std::left << std::setw(4) << q->key();
        }
        std::cout << std::endl;
    }

    for (SkipNode<T>* p = tail; p; p = p->above())
    {
        std::cout << std::left << std::setw(5) << "+INF";
    }
    std::cout << std::endl;
}
