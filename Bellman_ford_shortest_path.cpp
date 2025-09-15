#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Function to run Bellman-Ford algorithm
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Initialize distances to all vertices as infinity (1e8 used as infinity here)
        vector<int> dist(V, 1e8);
        
        // Distance to the source is 0
        dist[src] = 0;
        
        // Relax all edges V-1 times
        for(int i = 0; i < V - 1; i++) {
            for(auto it : edges) {
                int u = it[0];  // Source node of the edge
                int v = it[1];  // Destination node of the edge
                int wt = it[2]; // Weight of the edge
                
                // If the current distance to u is not infinity and relaxing gives a shorter path
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt; // Update distance to v
                }
            }
        }
        
        // Check for negative weight cycles
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // If we can still relax an edge, then there is a negative cycle
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1}; // Return {-1} if negative cycle is detected
            }
        }
        
        // Return the final distances
        return dist;
    }
};

int main() {
    int V, E, src;
    cin >> V >> E; // Number of vertices and edges
    vector<vector<int>> edges(E, vector<int>(3)); // edges[i] = {u, v, wt}
    
    for(int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2]; // input edge u, v and wt
    }
    cin >> src; // source vertex
    
    Solution solution;
    vector<int> result = solution.bellmanFord(V, edges, src);
    
    // Output the result
    if(result.size() == 1 && result[0] == -1) {
        cout << "Negative weight cycle detected." << endl;
    } else {
        cout << "Shortest distances from source vertex " << src << ":\n";
        for(int i = 0; i < V; i++) {
            if(result[i] == 1e8)
                cout << "INF "; // Unreachable vertex
            else
                cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
