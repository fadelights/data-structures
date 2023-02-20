#ifndef WEIGHTEDGRAPH_H_INCLUDED
#define WEIGHTEDGRAPH_H_INCLUDED

#include <iostream>
#include <limits>
#include <tuple>
#include <list>
#include <queue>
#include <vector>
#include "../../disjoint-sets/DisjointSets.h"

#define INF std::numeric_limits<int>::max()

typedef std::pair<int, int> i_pair;
typedef std::tuple<int, int, int> i_tuple;

class WeightedGraph
{
    public:
        WeightedGraph(int);
        void addUndirectedEdge(int, int, int);
        int kruskalMST();
        int primMST();

    private:
        int vertices;
        std::list<i_pair>* adjacencyList;
};

WeightedGraph::WeightedGraph(int vertex_count)
    : vertices{vertex_count}
{
    adjacencyList = new std::list<i_pair>[vertices];
}

void WeightedGraph::addUndirectedEdge(int u, int v, int weight)
{
    adjacencyList[u].push_back(std::make_pair(v, weight));
    
    if (u != v)
        adjacencyList[v].push_back(std::make_pair(u, weight));
}

int WeightedGraph::kruskalMST()
{
    // step 1: create a list of all edges
    std::list<i_tuple> edges; // tuple containing (weight, u, v)
    for (int i{0}; i < vertices; i++)
    {
        for (auto iter: adjacencyList[i])
        {
            if (iter.first > i) // prevent adding edges twice
                edges.push_back({iter.second, i, iter.first});
        }
    }

    // step 2: sort all edges in ascending order
    edges.sort(); // sorts based on the first element of each tuple (weight)
    
    // step 3: detect meshes using DisjointSets and run the algorithm
    DisjointSets ds(vertices);
    int mst_weight{0};
    int u, v, set_u, set_v;

    for (auto iter: edges)
    {
        u = std::get<1>(iter);
        v = std::get<2>(iter);

        set_u = ds.collapsingFind(u);
        set_v = ds.collapsingFind(v);

        if (set_u != set_v)
        {
            // std::cout << u << " <-> " << v << std::endl;
            std::cout << static_cast<char>('a' + u)
                      << " <-> "
                      << static_cast<char>('a' + v)
                      << "\t" << "(Weight: " << std::get<0>(iter) << ")"
                      << std::endl;

            ds.weightedUnion(set_u, set_v);
            mst_weight += std::get<0>(iter);
        }
    }

    return mst_weight;
}

int WeightedGraph::primMST()
{
    std::priority_queue<
                        i_pair, // pair consisting of (weight, vertex)
                        std::vector<i_pair>,
                        std::greater<i_pair>
                        > pq;
    
    std::vector<int> key(vertices, INF);
    std::vector<int> parent(vertices, -1);
    std::vector<bool> isin_mst(vertices, false);
    int mst_weight{0};

    pq.push({0, 0});
    key[0] = 0;

    int u, v, weight, tree_size{0};
    while (tree_size < vertices)
    {
        u = pq.top().second;
        pq.pop();

        if (isin_mst[u])
            continue;

        isin_mst[u] = true;
        tree_size++;

        if (u != 0) // filter the first vertex with no parent
        {
            mst_weight += key[u];
            std::cout << "("
                    << parent[u] << ", " << u
                    << ")" << " - "
                    << "Weight: " << key[u]
                    << std::endl;
        }

        for (auto iter: adjacencyList[u])
        {
            v = iter.first;
            weight = iter.second;

            if (!isin_mst[v] && weight < key[v])
            {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    return mst_weight;
}

#endif // WEIGHTEDGRAPH_H_INCLUDED
