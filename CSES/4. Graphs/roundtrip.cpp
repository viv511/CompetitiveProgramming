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
vector<int> parents;
vector<bool> visited;
vector< vector<int> > g;
 
int sv, ev;
 
bool dfs(int u, int par) {
    parents[u] = par;
    visited[u] = true;
 
    for(auto v : g[u]) {
        if(v == par) {
            continue; //Skip
        }
        if(visited[v]) {
            sv = v;
            ev = u;
            return true;
        }
        if(!visited[v]) {
            if(dfs(v, u)) {
                return true;
            }
        }
    }
    return false;
}
 
bool lookCC() {
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                return true;
            }
        }
 
    }
 
    return false;
}
 
 
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;
 
    g.resize(n+1);
    visited.resize(n+1);
    parents.resize(n+1);
 
    for(int i=0; i<m; i++) {
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
 
    if(!lookCC()) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
 
    vector<int> ans;
    ans.push_back(sv);
    int indexVal = ev;
    while(indexVal != sv) {
        ans.push_back(indexVal);
        indexVal = parents[indexVal];
    }
    ans.push_back(sv);
 
    cout << ans.size() << "\n";
    for(auto a : ans) {
        cout << a << " ";
    }
 
}
