//BFS
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
vector<vector<int>> g;
vector<int> par;
vector<bool> visited;
 
void bfs() {
    visited[1] = true;
 
    queue<int> q;
    q.push(1);
 
    while(!q.empty()) {
        int u = q.front();
        q.pop();
 
        for(auto v : g[u]) {
           if(!visited[v]) {
                visited[v] = true;
                par[v] = u;
                q.push(v);
           }
        }
    }
 
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;
 
    g.resize(n+1);
	visited.resize(n+1);
	par.resize(n+1);
 
    fill(par.begin(), par.end(), -1);
 
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
 
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    bfs();
 
    if(par[n] != -1) {
        vector<int> ans;
        ans.push_back(n);
        int curIndex = n;
 
        while(par[curIndex] != -1) {
            int parent = par[curIndex];
            ans.push_back(parent);
            curIndex = parent;
        }
 
        cout << ans.size() << "\n";
        for(int i=ans.size()-1; i>=0; i--) {
            cout << ans[i] << " ";
        }
        
    }
    else {
        cout << "IMPOSSIBLE";
    }
 
    return 0;
}