//CSES - Building Roads
#include <iostream>
#include <map>
#include <queue>
#include <list>
 
using namespace std;
 
//Main solution:
/*
Solve the number of connected components (cc)
 
It can be proven that the minimum number of roads that need to be built is the same as cc-1.
i.e. one road to connect each connected component consecutively
*/
 
int n, m; 
int cc = 0;
vector<vector<int>> g;
vector<bool> visited;
vector<int> lead; //Store a node from each independent connected component
//Answer will be consecutive pairs of lead [i.e. cc-1 roads need to be built]
 
void dfs(int u) {
    visited[u] = true;
    for(auto v : g[u]) {
        if(!visited[v]) {
            dfs(v);
        }
    }
}
 
void process_cc() {
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            cc++;
            lead.push_back(i);
            dfs(i);
        }
    }
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
    cin >> n >> m;
    g.resize(n+1);
    visited.resize(n+1);
 
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b; //adjacency list
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    process_cc();
 
    cout << cc-1 << "\n";
 
    if(cc > 1) {
        for(int i=0; i<cc; i++) {
            if(i == cc-1) {
                continue;
            }
            cout << lead[i] << " " << lead[i+1] << "\n";
        }
    }
}