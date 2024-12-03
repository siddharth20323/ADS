#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

void bellman_ford(int v, int e, int edges[][3], int src)
{
    int dist[v];   
    for (int i = 0; i < v; i++) {
        dist[i] = INT_MAX;   
    }
    dist[src] = 0;   

     
    for (int i = 0; i < v - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;  
            }
        }
    }

     //NEGATIVE CYCLE
    for (int j = 0; j < e; j++) {
        int u = edges[j][0];
        int v = edges[j][1];
        int w = edges[j][2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Negative weight cycle detected" << endl;
            return;
        }
    }

    // Output 
    cout << "Shortest distances from source (" << src << "):" << endl;
    for (int i = 0; i < v; i++) {
        if (dist[i] == INT_MAX) {
            cout << i << ": INF" << endl;  // If the vertex is unreachable
        } else {
            cout << i << ": " << dist[i] << endl;
        }
    }
}

int main() {
     
    int v = 5;  // Number of vertices
    int e = 6;  // Number of edges

    // Edge list: {u, v, weight}
    int edges[6][3] = {
        {0, 1, 5},  // Edge from 0 to 1 with weight 5
        {1, 3, 15}, // Edge from 1 to 3 with weight 15
        {2, 3, 4},  // Edge from 2 to 3 with weight 4
        {2, 0, 6},  // Edge from 2 to 0 with weight 6
        {0, 3, 5},  // Edge from 0 to 3 with weight 5
        {1, 2, 1}   // Edge from 1 to 2 with weight 1
    };

    int src = 0; // Source vertex

    bellman_ford(v, e, edges, src); 

    return 0;
}


 
 