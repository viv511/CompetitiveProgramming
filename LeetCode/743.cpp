#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define ll long long

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<ll, int>>> adj(n + 1);

    for (int t = 0; t < times.size(); t++) {
        int u = times[t][0];
        int v = times[t][1];
        ll w = times[t][2];

        adj[u].push_back({w, v});
    }

    vector<ll> dist(n + 1, LLONG_MAX);
    vector<bool> done(n + 1, false);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // dijkstra + find the max across all nodes
    // if equal to LLONG_MAX, return -1
    
    dist[k] = 0;
    pq.push({0, k});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (done[u]) continue;
        done[u] = true;

        for (auto [w, v] : adj[u]) {
            ll dNew = d + w;

            if (dNew < dist[v]) {
                dist[v] = dNew;
                pq.push({dNew, v});
            }
        }

    }

    ll maxDist = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == LLONG_MAX) return -1;
        maxDist = max(maxDist, dist[i]);
    }

    return maxDist;
}