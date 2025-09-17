
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// User Function Template
class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Code here

        // Create adjacency list from edge list
        vector<vector<pair<int, int>>> adj(V);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({ v,wt });
            adj[v].push_back({ u,wt });
        }

        // Dijkstra's algorithm starts here

        int n = adj.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n);
        for (int i = 0; i < V; i++) dist[i] = 1e9;

        dist[src] = 0;

        pq.push({ 0, src });

        while (!pq.empty()) {
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto nebr : adj[node]) {
                int edgewt = nebr.second;
                int adjNode = nebr.first;

                if (distance + edgewt < dist[adjNode]) {
                    dist[adjNode] = distance + edgewt;
                    pq.push({ dist[adjNode], adjNode });
                }
            }
        }

        return dist;
    }
};

// Main function to test the above solution
int main() {
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    vector<vector<int>> edges(E, vector<int>(3));
    cout << "Enter each edge as: u v weight\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;
    cout << "Enter source vertex:\n";
    cin >> src;

    Solution solution;
    vector<int> result = solution.dijkstra(V, edges, src);

    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << " -> " << result[i] << endl;
    }

    return 0;
}
