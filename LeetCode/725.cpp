#include <vector>
using namespace std; 

vector<int> col;
int n;

bool dfs(vector<vector<int>>& G, int u, int c) {
    if (col[u] != -1) {
        return col[u] == c;
    }

    col[u] = c;

    bool curr = true;
    for (int v : G[u]) {
        curr &= dfs(G, v, 1 - c);
    }

    return curr;
}

bool isBipartite(vector<vector<int>>& graph) {
    n = graph.size();
    col.resize(n, -1);

    bool res = true;

    for (int i = 0; i < n; i++) {
        if (col[i] == -1) {
            res &= dfs(graph, i, 0);
        }
    }

    return res;
}