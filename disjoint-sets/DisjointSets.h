#include <iostream>
#include <algorithm>

class DisjointSets
{
    public:
        DisjointSets(int);
        int simpleFind(int) const;
        void simpleUnion(int, int);
        void weightedUnion(int, int);
        int collapsingFind(int);
        void printSets() const;
    
    private:
        bool isValidIndex(int) const;

        int* parent;
        int size;
};

DisjointSets::DisjointSets(int numberOfElements)
{
    if (numberOfElements < 2)
        throw std::runtime_error("DisjointSets needs at least 2 elements");
    
    size = numberOfElements;
    parent = new int[size];
    std::fill(parent, parent + size, -1);
}

bool DisjointSets::isValidIndex(int index) const
{
    return index >= 0 && index < size;
}

int DisjointSets::simpleFind(int index) const
{
    if (!isValidIndex(index))
        throw std::runtime_error("Invalid index");
    
    while (parent[index] >= 0)
        index = parent[index];
    
    return index;
}

void DisjointSets::simpleUnion(int i, int j)
{
    if (!isValidIndex(i) || !isValidIndex(j))
        throw std::runtime_error("Invalid index");
    
    i = simpleFind(i);
    j = simpleFind(j);

    if (i == j)
        return;
    
    parent[i] = j;
}

void DisjointSets::weightedUnion(int i, int j)
{
    if (!isValidIndex(i) || !isValidIndex(j))
        throw std::runtime_error("Invalid index");
    
    i = simpleFind(i);
    j = simpleFind(j);

    if (i == j)
        return;
    
    if (parent[i] >= parent[j])
    {
        // set roots are negative!
        parent[j] += parent[i];
        parent[i] = j;
    }

    else
    {
        parent[i] += parent[j];
        parent[j] = i;
    }
}

int DisjointSets::collapsingFind(int index)
{
    if (!isValidIndex(index))
        throw std::runtime_error("Invalid index");
    
    int root = simpleFind(index);
    int tmp;
    while (index != root)
    {
        tmp = index;
        index = parent[index];
        parent[tmp] = root;
    }

    return root;
}

void DisjointSets::printSets() const
{
    for (int i = 0; i < size; i++)
        std::cout << "parent[" << i << "]: " << parent[i] << std::endl;
}
