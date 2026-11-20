#include <vector>
using namespace std;

bool dfs(vector<vector<int>>& adj, vector<bool>& visited, int u, int target) {
    if (u == target) return true;
    
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(adj, visited, v, target)) {
                return true;
            }
        }
    }

    return false;
}

vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    int n = numCourses;

    vector<vector<int>> adj(n);
    for (auto&p : prerequisites) {
        adj[p[0]].push_back(p[1]);
    }

    vector<bool> ans;
    vector<bool> visited(n, false);

    for (auto&q : queries) {
        visited.clear();
        visited.resize(n, false);

        // dfs? or smth else here
        int u = q[0];
        int v = q[1];

        ans.push_back(dfs(adj, visited, u, v));
    }

    return ans;
}