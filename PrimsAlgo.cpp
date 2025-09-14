#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // Create adjacency list from edge list
        vector<vector<pair<int, int>>> adj(V);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({ v, wt });
            adj[v].push_back({ u, wt }); // since it's an undirected graph
        }

        // Prim's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);
        int sum = 0;

        pq.push({ 0, 0 }); // {weight, node}

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            if (vis[node]) continue;

            vis[node] = 1;
            sum += wt;

            for (auto neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int edgeweight = neighbor.second;
                if (!vis[adjNode]) {
                    pq.push({ edgeweight, adjNode });
                }
            }
        }

        return sum;
    }
};

int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };
    cout << "Minimum Spanning Tree cost: " << sol.spanningTree(V, edges) << endl;
    return 0;
}
