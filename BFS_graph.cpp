#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        vector<int> bfsResult;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfsResult.push_back(node);
            
            for (auto it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
       
        return bfsResult;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    cout << "Enter each edge (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // because it's an undirected graph
    }
    
    Solution solution;
    vector<int> result = solution.bfs(adj);
    
    cout << "BFS traversal starting from node 0:" << endl;
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}
