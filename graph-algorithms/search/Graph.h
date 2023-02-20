#include <iostream>
#include <list>

class Graph
{
    public:
        Graph(int);
        ~Graph();
        void addEdge(int, int);
        void addUndirectedEdge(int, int);
        void BFS(int);
        void DFS();

    private:
        void DFSVisit(int, bool []);
        
        int vertexCount;
        std::list<int>* adjacencyList;
};

Graph::Graph(int n)
    : vertexCount{n}
{
    adjacencyList = new std::list<int>[vertexCount];
}

Graph::~Graph()
{
    delete [] adjacencyList;
}

void Graph::addEdge(int u, int v)
{
    adjacencyList[u].push_back(v);
}

void Graph::addUndirectedEdge(int v, int u)
{
    adjacencyList[u].push_back(v);
    adjacencyList[v].push_back(u);
}

void Graph::BFS(int start)
{
    bool* visited{new bool[vertexCount]};
    std::fill(visited, visited + vertexCount, false);

    std::list<int> queue;
    
    visited[start] = true;
    queue.push_back(start);

    while (!queue.empty())
    {
        start = queue.front();
        std::cout << start << " ";
        queue.pop_front();

        for (auto i: adjacencyList[start])
        {
            if (!visited[i])
            {
                visited[i] = true;
                queue.push_back(i);
            }
        }
    }

    delete [] visited;
    std::cout << std::endl;
}

void Graph::DFSVisit(int start, bool visited[])
{
    visited[start] = true;
    std::cout << start << " ";

    for (auto i: adjacencyList[start])
    {
        if (!visited[i])
        {
            DFSVisit(i, visited);
        }
    }
}

void Graph::DFS()
{
    bool* visited{new bool[vertexCount]};
    std::fill(visited, visited + vertexCount, false);

    for (int i{0}; i < vertexCount; i++)
    {
        if (!visited[i])
        {
            DFSVisit(i, visited);
        }
    }

    delete [] visited;
    std::cout << std::endl;
}
