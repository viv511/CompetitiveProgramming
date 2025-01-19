#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

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


void solve() {
    int n; cin >> n;
    
    if(n == 1) {
        yap("1");
        yap("1");
    }
    else if (n == 2) {
        yap("2");
        yap("1 2");
    }
    else if (n == 3) {
        yap("2");
        yap("1 2 2");
    }
    else if (n == 4) {
        yap("3");
        yap("1 2 2 3");
    }
    else if (n == 5) {
        yap("3");
        yap("1 2 2 3 3");
    }
    else if (n == 6) {
        yap("4");
        yap("1 2 3 3 4");
    }
    else {
        yap("4");

        for(int i=1; i<=n; i++) {
            cout << i % 4 + 1 << " ";
        }
        cout << "\n";
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