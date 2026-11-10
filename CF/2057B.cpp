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
	int n, k;
    cin >> n >> k;

    map<int, int> m;
    F0R(i, n) {
        int x; cin >> x;
        m[x]++;
    }

    vi count;
    for(auto x : m) {
        count.pb(x.se);
    }

    sort(all(count));
    for (int i = 0; i < sz(count) - 1; i++) {
        if (count[i] > k) {
            yap(sz(count)-i); 
            return;
        }
        k -= count[i];
    }

    yap(1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}