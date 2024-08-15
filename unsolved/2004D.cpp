#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

#define MAX 1e12
#define ll long long

using namespace std;

bool checkPortal(string s1, string s2) {
    if(s1[0] == s2[0] || s1[1] == s2[1]) {
        return true;
    }
    return false;
}

void solve() {
	ll n, queries; cin >> n >> queries;

    vector<ll> distance(n, MAX);
    vector<bool> processed(n, false);
    vector<pair<ll, ll>> adj[n];

    vector<string> portals;
    for(ll i=0; i<n; i++) {
        string s; cin >> s;
        portals.push_back(s);
    }

    for(ll i = 0; i < n; i++) {
        for(ll j = i+1; j < n; j++) {
            if(checkPortal(portals[i], portals[j])) {
                adj[i].push_back({j, abs(j-i)});
                adj[j].push_back({i, abs(j-i)});
            }
        }
    }

    for(ll i=0; i<queries; i++) {
        fill(distance.begin(), distance.end(), MAX);
        fill(processed.begin(), processed.end(), false);

        ll startNode, endNode; cin >> startNode >> endNode;
        startNode--; endNode--;

        if(startNode == endNode) {
            cout << 0ll << "\n";
        }
        else {
            priority_queue<pair<ll, ll>> q;

            distance[startNode] = 0ll;
            q.push({0, startNode});

            while(!q.empty()) {
                ll a = q.top().second;
                q.pop();

                if(processed[a]) {
                    continue;
                }
                processed[a] = true;

                for (auto u : adj[a]) {
                    ll b = u.first;
                    ll w = u.second;

                    if(distance[a] + w < distance[b]) {
                        distance[b] = distance[a] + w;
                        q.push({-distance[b], b});
                    }
                }
            }

            if(distance[endNode] == MAX) {
                cout << -1 << "\n";
            }
            else {
                cout << distance[endNode] << "\n";
            }
        }
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll T; cin >> T;
	while(T--) {
		solve();
	}
}
