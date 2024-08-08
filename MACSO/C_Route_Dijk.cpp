#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1e9

int main() {
    int cities, roads;
    cin >> cities >> roads;

    vector<int> distance(cities+1, MAX);
    vector<bool> processed(cities+1, false);
    vector<pair<int, int>> adj[cities+1];

    for (int i = 0; i < roads; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    priority_queue<pair<int, int>> q;

    int startNode, endNode;
    cin >> startNode >> endNode;

    distance[startNode] = 0;
    q.push({0, startNode});

    while(!q.empty()) {
        int a = q.top().second;
        q.pop();

        if(processed[a]) {
            continue;
        }
        processed[a] = true;

        for (auto u : adj[a]) {
            int b = u.first;
            int w = u.second;

            if(distance[a] + w < distance[b]) {
                distance[b] = distance[a] + w;
                q.push({-distance[b], b});
            }
        }
    }

    if(distance[endNode] == MAX) {
        cout << -1;
    }
    else {
        cout << distance[endNode];
    }
}