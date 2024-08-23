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
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())

using namespace std;

#define MAXN 1000

vector<long long> a;
bool visited[MAXN];
vi adj[MAXN];

void printNum(long long v) {
    cout << v << " ";
}

void dfs(int s) {
    if(visited[s]) return;

    visited[s] = true;
    printNum(a[s]);
    for(int u : adj[s]) {
        dfs(u);
    }
}

void solve() {
	int n; cin >> n;

    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        visited[i] = false;
    }

    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if( ((float)a[j]/(float)a[i] == 3) || ((float)a[i]/(float)a[j] == 3) || ((float)a[j]/(float)a[i] == 2) || ((float)a[i]/(float)a[j] == 2)) {
                adj[i].pb(j);
                adj[j].pb(i);
            }
        }
    }

    int startNode = 0;
    for(int i=0; i<n; i++){
        if(adj[i].size() == 1) {

            int nextNode = adj[i][0];
            int curNode = i;

            if(a[curNode] * 2 == a[nextNode] || a[curNode]/a[nextNode] == 3) {
                startNode = i;
                break;
            }
        }
    }

    dfs(startNode);
    // cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}