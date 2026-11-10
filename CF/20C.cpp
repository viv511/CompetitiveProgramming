#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
    cin >> n >> m;

    vector<vector<pair<long long, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;

        a--;
        b--;

        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    // SSSP - undirected, positive edge weights

    vector<long long> dist(n, LLONG_MAX);
    vector<bool> done(n, false);
    vector<int> parent(n, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (done[u]) continue;
        done[u] = true;

        for (auto [w, v] : adj[u]) {
            long long newDist = d + w;
            if (newDist < dist[v]) {
                dist[v] = newDist;
                parent[v] = u;
                pq.push({newDist, v});
            }
        }
    }

    if (dist[n - 1] == LLONG_MAX) {
        cout << -1 << "\n";
    }
    else {
        vector<int> ans;
        
        for (int v = n-1; v != -1; v = parent[v]) {
            ans.push_back(v);
        }

        reverse(ans.begin(), ans.end());

        for (int v : ans) {
            cout << v + 1 << " ";
        }
    }
}