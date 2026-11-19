#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<ll, int>>> adj(n);

    for (auto& r : roads) {
        int u = r[0];
        int v = r[1];
        ll w = r[2];

        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    vector<ll> dist(n, LLONG_MAX);
    vector<int> ways(n, 0);
    vector<bool> done(n, false);

    dist[0] = 0;
    ways[0] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (done[u]) continue;
        done[u] = true;

        for (auto [w, v] : adj[u]) {
            ll newD = d + w;

            if (newD < dist[v]) {
                dist[v] = newD;
                ways[v] = ways[u]; //reset
                pq.push({newD, v});
            }
            else if (newD == dist[v]) {
                ways[v] = (ways[v] + ways[u]) % MOD; //add ways
            }
        }
    }

    return ways[n-1];
}