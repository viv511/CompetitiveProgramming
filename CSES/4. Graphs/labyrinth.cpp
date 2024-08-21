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
vector<vector<pair<int, int>>> path;
vector<vector<bool>> visited;
int sX, sY, eX, eY;
vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
 
bool isValid(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
 
    return true;
}
 
void bfs() {
    queue<pair<int, int>> q;
 
    q.push({sX, sY});
 
    while(!q.empty()) {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
 
        for(auto move : moves) {
            int moveX = curX + move.first;
            int moveY = curY + move.second;
 
            if(isValid(moveX, moveY)) {
                q.push({moveX, moveY});
                visited[moveX][moveY] = true;
                path[moveX][moveY] = {move.first, move.second};
            }
 
        }
    }
 
}
 
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    cin >> n >> m;
 
    path.resize(n);
    visited.resize(n);
    for(int i=0; i<n; i++) {
        path[i].resize(m);
        visited[i].resize(m);
    }
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            path[i][j] = {-1, -1};
            char c; cin >> c;
 
            if(c == '#') {
                visited[i][j] = true;
            }
            else if(c == 'A') {
                sX = i;
                sY = j;
            }
            else if(c == 'B') {
                eX = i;
                eY = j;
            }
        }
    }
 
    bfs();
 
    if(visited[eX][eY]) {
        cout << "YES\n";
 
        vector<pair<int, int>> ans;
    
        pair<int, int> end = {eX, eY};
        while(!(end.first == sX) || !(end.second == sY)) {
            pair<int, int> desiredMove = path[end.first][end.second];
            ans.push_back(desiredMove);
 
            end.first -= desiredMove.first;
            end.second -= desiredMove.second;
        }
 
        string fullPath = "";
        for(auto a : ans) {
            if(a.first == -1 && a.second == 0) {
                fullPath += "U";
            }
            if(a.first == 1 && a.second == 0) {
                fullPath += "D";
            }
            if(a.first == 0 && a.second == 1) {
                fullPath += "R";
            }
            if(a.first == 0 && a.second == -1) {
                fullPath += "L";
            }
        }
 
        reverse(fullPath.begin(), fullPath.end());
        cout << fullPath.length() << "\n" << fullPath;
    }
    else{
        cout << "NO\n";
    }
 
 
}