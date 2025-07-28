#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;

#define yap(answer) cout << answer << "\n"

void solve() {
    ll n; cin >> n;
    vector<ll> shells(n);

    for(ll i = 0; i < n; i++) {
        ll x; cin >> x;
        shells[i] = __builtin_popcount(x);
    }

    ll ans = 0;
    
    for(ll l = 0; l < n; l++) {
        for(ll r = l+1; r < n; r++) {
            
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