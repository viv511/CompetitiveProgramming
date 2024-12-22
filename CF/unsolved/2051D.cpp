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
typedef vector<int> vi;

#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

void solve() {
	ll n; cin >> n;
    ll lBound, rBound; cin >> lBound >> rBound;

    ll totalSum = 0;
    vi seq(n);

    F0R(i, n) {
        cin >> seq[i];
        totalSum += seq[i];
    }

    sort(seq.begin(), seq.end());


    ll ans = 0;
    for(ll i=0; i<n; i++) {
        for(ll j=i+1; j<n; j++) {
            ll newSum = totalSum - seq[i] - seq[j];
            if(newSum >= lBound && newSum <= rBound) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll T; cin >> T;
	while(T--) {
		solve();
	}
}

/*
4
7
0
0
1
5
6

*/

