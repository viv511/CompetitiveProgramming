//Bipartite Graph coloring
 
#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <list>
 
using namespace std;
 
int n, m;
vector<bool> visited;
vector<vector<int>> g;
vector<int> color;
 
bool bfs(int startNode) {
    queue<int> q;
 
    q.push(startNode);
 
    color[startNode] = 1;
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : g[u]) {
           if(color[v] == -1) {
                color[v] =  1 - color[u]; //flip 0 or 1
                q.push(v);
                visited[v] = true;
            }
            else if(color[v] == color[u]) {
                return false;
            }
        }
 
    }
 
    return true;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;
 
    g.resize(n+1);
    visited.resize(n+1);
    color.resize(n+1, -1);
 
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
 
    bool ans = true;
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            if(!bfs(i)) {
                ans = false;
                break;
            }
        }
    }
 
    if(ans) {
        for(int i=1; i<color.size(); i++) {
            if(color[i] == -1) {
                cout << 1 << " ";
            }
            else {
                cout << color[i]+1 << " ";
            }
        }
    }
    else {
        cout << "IMPOSSIBLE\n";
    }
    
 
 
}
