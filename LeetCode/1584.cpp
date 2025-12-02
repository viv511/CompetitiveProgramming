#include <queue>
#include <vector>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;

int manhatDist(const vector<vector<int>>& points, int i, int j) {
    return abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
}

//bfs + visit hash set + pq/min-heap
int minCostConnectPoints(vector<vector<int>>& points) {
    //assuming a fully connected graph w/ prims algorithm
    int n = points.size();

    vector<bool> visited(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0}); 

    int ans = 0;
    int visitedCount = 0;

    while(visitedCount < n) {
        //will run til non visited edge found
        auto a = pq.top();
        int cost = a.first;
        int i = a.second;
        
        pq.pop();
        if(visited[i]) continue;

        //add to MST
        visited[i] = true;
        visitedCount++;
        ans += cost;
        
        //add all other edges
        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int dist = manhatDist(points, i, j);
                pq.push({dist, j});
            }
        }
    }

    return ans;
}