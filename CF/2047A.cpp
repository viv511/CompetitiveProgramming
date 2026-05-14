#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
	int n; cin >> n;
    
    int ans = 0;

    vi v(n);
    
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }
    // guaranteed to have at least one tile dropped, first day is a success
    ans++;

    for(int i=1; i<n; i++) {
        v[i] += v[i-1];

        ll rootV = sqrt(v[i]);

        if((rootV * rootV == v[i]) && (rootV % 2 == 1)) {
            // cout << v[i] << "!\n";
            ans++;
        }
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    // precompute all differences?
    // max # of tiles there could be is 100 tiles per 100 days
    // 10000 tiles total
    // i.e. 100^2 (max square could be 100 by 100
    // thus all we do is compute the first 100 squares and put them in a set
    // run a prefix sum on each v (o(n)) time and check after summing if its in thr set or not o(1)
    // thus o(n) for each test case

	int T; cin >> T;
	while(T--) {
		solve();
	}
}