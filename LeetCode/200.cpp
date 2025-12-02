#include <vector>
using namespace std;

int find(vector<int>& P, int x) {
    if(P[x] < 0) return x;

    P[x] = find(P, P[x]);

    return P[x];
}

int ufIndex(int i, int j, vector<vector<char>>& grid) {
    return i * grid[0].size() + j;
}

int numIslands(vector<vector<char>>& grid) {
    //union find
    int count = 0;

    //flatten into a 1d array
    //index = row * numCols + col

    vector<int> uf(grid.size() * grid[0].size(), -1);

    //perform unions with only right and down
    for(int i=0; i<grid.size(); i++) {
        for(int j=0; j<grid[0].size(); j++) {
            if(grid[i][j] == '1') {
                count++;

                //union right
                if(j + 1 < grid[0].size() && grid[i][j+1] == '1') {
                    int u1 = ufIndex(i, j, grid);
                    int u2 = ufIndex(i, j+1, grid);

                    int r1 = find(uf, u1);
                    int r2 = find(uf, u2);

                    if(r1 != r2) {
                        uf[r2] = r1;
                        count--;
                    }
                }
                
                //union down
                if(i + 1 < grid.size() && grid[i+1][j] == '1') {
                    int u1 = ufIndex(i, j, grid);
                    int u2 = ufIndex(i+1, j, grid);

                    int r1 = find(uf, u1);
                    int r2 = find(uf, u2);

                    if(r1 != r2) {
                        uf[r2] = r1;
                        count--;
                    }
                }
            }
        }
    }

    return count;
}