#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)(x.size())

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

int countCycleNodes() {
	int cycleNodes = 0;
	
	for(int i=1; i<=g.size(); i++) {
        if(!visited[i]) {
            if(dfs(i, -1)) {
                
            }
        }
 
    }

	return cycleNodes;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//Convert from [r, c] to [1, n^2]
	auto conv = [&](int r, int c) {
		return (r-1)*n + c;
	};

	map<char, pi> moves;
	moves['L'] = mp(0, -1);
	moves['R'] = mp(0, 1);
	moves['U'] = mp(-1, 0);
	moves['D'] = mp(1, 0);

	int n; cin >> n;
	int q; cin >> q;

	//Create graph w/ n*n nodes & q roads

	g.resize((n*n)+1);
    visited.resize((n*n)+1);
    parents.resize((n*n)+1);

	for(int i=0; i<q; i++) {
		int r, c; cin >> r >> c;
		char dir; cin >> dir;

		int dr = moves[dir].fi;
		int dc = moves[dir].se;

		//Check bounds
		if(r+dr < 1 || r+dr > n || c+dc < 1 || c+dc > n) {
			continue;
		}

        g[conv(r, c)].push_back(conv(r+dr, c+dc));

		//Reset visited
		fill(visited.begin(), visited.end(), false);

		//Run DFS to find CCs? 


		//Check all remaining cells to see if they have a "false" neighbor

	}
}