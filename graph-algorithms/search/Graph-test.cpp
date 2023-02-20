#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
    // creating the same graph as the slides
    Graph g(10);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 5);
    g.addEdge(0, 7);

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 4);

    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 3);

    g.addEdge(4, 3);

    g.addEdge(5, 3);
    g.addEdge(5, 4);
    g.addEdge(5, 6);
    g.addEdge(5, 7);

    g.addEdge(6, 5);
    g.addEdge(6, 7);

    g.addUndirectedEdge(8, 9);
    g.addEdge(8, 7);
    g.addEdge(9, 6);

    cout << "BFS: " << endl;
    g.BFS(0);

    cout << '\n' << "DFS: " << endl;
    g.DFS();

    return 0;
}
