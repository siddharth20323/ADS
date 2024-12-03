 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class dsu
{
    int *parent;
    int *rank;

public:
    dsu(int n)
    {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i]);
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1]++;
            }
        }
    }
};

struct Edge
{
    int weight, u, v;

     
    Edge(int weight, int u, int v) : weight(weight), u(u), v(v) {}

    
    bool operator<(const Edge &e) const
    {
        return weight < e.weight;
    }
};

class Graph
{
    vector<Edge> edges;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

     
    void addEdge(int u, int v, int w)
    {
        edges.push_back(Edge(w, u, v));
    }

    void kruskal()
    {
        // Sort edges by weight
        sort(edges.begin(), edges.end());

        // Disjoint Set Union
        dsu ds(V);

        int mstw = 0;  // MST W
        cout << "Edges in the constructed MST:" << endl;

        // Process each edge in increasing order of weight
        for (const auto &edge : edges)
        {
            if (ds.find(edge.u) != ds.find(edge.v))
            {
                ds.unite(edge.u, edge.v);
                mstw += edge.weight;
                cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
            }
        }

        cout << "Minimum Cost Spanning Tree: " << mstw << endl;
    }
};

int main()
{
    
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);

     
    g.kruskal();

    return 0;
}

 
 