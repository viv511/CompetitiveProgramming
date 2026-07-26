#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef long long ll;

void solve() {
	int n; cin >> n;
    vector<ll> v(n+1);

    ll small = LLONG_MIN;
    ll large = LLONG_MAX;

    // for k to exist there has to be a suitable range

    for(int i=1; i<=n; i++) {
        ll a; cin >> a;

        if (i % 2 == 0) {
            small = max(small, a);
        } else {
            large = min(large, a);
        }

        v[i] = a;
    }

    if (n % 2 == 1) {
        cout << "NO" << "\n";
        return;
    }

    // then there is a range
    if (small + 1 < large) {
        cout << "YES" << "\n";
    }
    else {
        cout << "NO" << "\n";
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