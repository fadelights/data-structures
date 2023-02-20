#include <iostream>
#include "WeightedGraph.h"

using namespace std;

int main()
{
    // create a similar graph to the one in pdf
    WeightedGraph g(10);

    g.addUndirectedEdge(0, 1, 14);
    g.addUndirectedEdge(0, 7, 14);

    g.addUndirectedEdge(1, 2, 11);
    g.addUndirectedEdge(1, 7, 12);
    g.addUndirectedEdge(1, 8, 3);

    g.addUndirectedEdge(2, 3, 9);
    g.addUndirectedEdge(2, 9, 2);
    g.addUndirectedEdge(2, 6, 8);
    g.addUndirectedEdge(2, 8, 6);

    g.addUndirectedEdge(3, 4, 5);
    g.addUndirectedEdge(3, 5, 10);
    g.addUndirectedEdge(3, 9, 15);

    g.addUndirectedEdge(4, 5, 13);

    g.addUndirectedEdge(5, 6, 4);
    g.addUndirectedEdge(5, 9, 2);

    g.addUndirectedEdge(6, 7, 1);
    g.addUndirectedEdge(6, 8, 7);
    g.addUndirectedEdge(6, 9, 5);

    g.addUndirectedEdge(7, 8, 16);

    cout << "\n" << "MST's edges are (Kruskal):" << "\n";
    int mst_weight_kr{g.kruskalMST()};
    cout << "MST's weight is: " << mst_weight_kr << endl;

    cout << "\n" << "MST's edges are (Prim):" << "\n";
    int mst_weight_pr{g.primMST()};
    cout << "MST's weight is: " << mst_weight_pr << endl;

    return 0;
}
