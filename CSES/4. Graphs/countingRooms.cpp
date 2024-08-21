//Grid dfs
#include <iostream>
#include <map>
#include <queue>
#include <list>
 
using namespace std;
 
int n, m, rooms; //N rows, M columns, Rooms = final answer
vector< vector<bool> > visited; //N x M matrix [T = closed, F = open]
vector< pair<int, int> > moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; //Up, Down, Left, Right
 
bool isValid(int x, int y) {
    if(x < 0 || x > n-1 || y < 0 || y > m-1) {
        return false;
    }
    if(visited[x][y]) {
        return false;
    }
 
    return true;
}
 
void dfs(int i, int j) {
    visited[i][j] = true; //Switch visibility
 
    for(auto pos : moves) {
        int pX = pos.first;
        int pY = pos.second;
 
        if(isValid(i+pX, j+pY)) {
            dfs(i+pX, j+pY);
        }
    }
}
 
void solve() {
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                dfs(i, j);
                rooms++;
            }
        }
    }
 
    cout << rooms;
}
 
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	visited.resize(n);
 
	for(int i = 0; i < n; i++) {
		visited[i].resize(m);
	}
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char a; cin >> a;
            if(a == '#') {
                visited[i][j] = true;
            }
            else {
                visited[i][j] = false;
            }
        }
    }
 
    solve();
 
    return 0;
}