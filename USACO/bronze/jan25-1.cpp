#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

bool inBounds(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

void solve() {
	int n, a, b;
    cin >> n >> a >> b;

    int greyBlack = 0;

    char pic[n][n];
    F0R(i, n) {
        F0R(j, n) {
            cin >> pic[i][j];

            if(pic[i][j] == 'G' || pic[i][j] == 'B') {
                greyBlack++;
            }
        }
    }

    int ans = 0;

    if(a == 0 && b == 0) {
        yap(greyBlack);
        return;
    }

    int gCount = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(pic[i][j] == 'G') { //Follow the chain, make a jump A to the right, B to down
                
                gCount = 1;
                pic[i][j] = 'W';
                ans++;

                int startX = i+b;
                int startY = j+a;

                while(inBounds(startX, startY, n)) {
                    if(pic[startX][startY] == 'W') { //Star must have disappeared
                        break;
                    }
                    else if(pic[startX][startY] == 'B') { //Chain of stars (B)
                        pic[startX][startY] = 'W';
                        ans++;
                    }
                    else { //You cant have more than 2 G's in a row of shifts
                        gCount++;

                        if(inBounds(startX+b, startY+a, n) && pic[startX+b][startY+a] == 'B') {
                            // ans--; //to negate the additional ++ later
                            break; //Start of B chain!! //Keep the G not colored & not incremented yet
                        }
                        else if(gCount % 2 == 0) {
                            pic[startX][startY] = 'W';   
                        }
                        else {
                            pic[startX][startY] = 'W';
                            ans++;
                        }
                    }

                    startX += b;
                    startY += a; //Continue jumping?
                }

            }
        }
    }

    //If array contains a "B" then it is invalid
    bool isInvalid = false;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(pic[i][j] == 'B') {
                isInvalid = true;
                break;
            }
        }
    }

    if(isInvalid) {
        yap(-1);
    }
    else {
        yap(ans);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}