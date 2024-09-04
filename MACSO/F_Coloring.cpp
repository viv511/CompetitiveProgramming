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
#define print(answer) cout << answer << "\n"

using namespace std;

void solve() {
    //Statically find the 9x12 grid ==> any subcombination of 3x3 grid will have a 3-coloring
    //if its 10x10 ill just take the WA :sobbing:
    
    //2-coloring
    //Anything 2xk works
    //3x3, 4, 5, 6 all works ==> 3x7+ doesnt work
    //4x4, 5, 6 all works ==> 4x7+ doesnt work

    int twoTall[6][4] = {
        {1, 1, 2, 2},
        {1, 2, 1, 2},
        {2, 1, 1, 2},
        {1, 2, 2, 1},
        {2, 1, 2, 1},
        {2, 2, 1, 1}
    };

    int twoFat[4][6] = {
        {1, 1, 2, 1, 2, 2},
        {1, 2, 1, 2, 1, 2},
        {2, 1, 1, 2, 2, 1},
        {2, 2, 2, 1, 1, 1}
    };

    // int threeTall[12][9] {
    //     //3 is white 2 is grey, 1 is black
    //     {1, 3, 2, 3, 2, 1, 2, 1, 3},
    //     {3, 2, 1, 2, 1, 3, 1, 3, 2},
    //     {2, 1, 3, 1, 3, 2, 3, 2, 1},
    //     {1, 2, 3, 1, 2, 3, 1, 2, 3},
    //     {3, 1, 2, 3, 1, 2, 3, 1, 2},
    //     {2, 3, 1, 2, 3, 1, 2, 3, 1},
    //     {1, 1, 1, 2, 2, 2, 3, 3, 3},
    //     {3, 3, 3, 1, 1, 1, 2, 2, 2},
    //     {2, 2, 2, 3, 3, 3, 1, 1, 1},
    //     {3, 1, 2, 2, 3, 1, 1, 2, 3},
    //     {2, 3, 1, 1, 2, 3, 3, 1, 2},
    //     {1, 2, 3, 3, 1, 2, 2, 3, 1}
    // };

    // int threeFat[9][12] = {
    //     //3 is white 2 is grey, 1 is black
    //     {1, 3, 2, 1, 3, 2, 1, 3, 2, 3, 2, 1},
    //     {3, 2, 1, 2, 1, 3, 1, 3, 2, 1, 3, 2},
    //     {2, 1, 3, 3, 2, 1, 1, 3, 2, 2, 1, 3},
    //     {3, 2, 1, 1, 3, 2, 2, 1, 3, 2, 1, 3},
    //     {2, 1, 3, 2, 1, 3, 2, 1, 3, 3, 2, 1},
    //     {1, 3, 2, 3, 2, 1, 2, 1, 3, 1, 3, 2},
    //     {2, 1, 3, 1, 3, 2, 3, 2, 1, 1, 3, 2},
    //     {1, 3, 2, 2, 1, 3, 3, 2, 1, 2, 1, 3},
    //     {3, 2, 1, 3, 2, 1, 3, 2, 1, 3, 2, 1}
    // };

    //Brute force and find the solution // then just use a look up table to solve
    int threeAll[10][10] = {
        {2, 3, 3, 1, 3, 1, 2, 3, 2, 1},
        {2, 2, 1, 2, 3, 3, 3, 1, 3, 1},
        {1, 2, 3, 1, 2, 2, 1, 1, 3, 3},
        {1, 2, 2, 3, 1, 1, 3, 3, 2, 3},
        {3, 1, 3, 2, 2, 1, 3, 1, 2, 2},
        {1, 1, 3, 3, 2, 3, 2, 2, 1, 1},
        {3, 1, 1, 1, 1, 2, 2, 3, 3, 2},
        {3, 3, 2, 2, 1, 3, 2, 1, 1, 3},
        {3, 2, 1, 3, 3, 1, 1, 2, 1, 2},
        {2, 3, 2, 3, 1, 2, 1, 2, 3, 1}
    };

    int n, m; cin >> n >> m;
    int c; cin >> c;

    if(c == 2) {
        if(n == 2) {
            for(int j=0; j<m; j++) {
                cout << 1 << " ";
            }
            cout << "\n";

            for(int j=0; j<m; j++) {
                cout << 2 << " ";
            }
            cout << "\n";
        }
        else if(m == 2) {
            for(int i=0; i<n; i++) {
                cout << 1 << " " << 2 << "\n";
            }
        }
        else if(n > m) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << twoTall[i][j] << " ";
                }
                cout << "\n";
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    cout << twoFat[i][j] << " ";
                }
                cout << "\n";
            }
        }
    }
    else {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << threeAll[i][j] << " ";
            }
            cout << "\n";
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}