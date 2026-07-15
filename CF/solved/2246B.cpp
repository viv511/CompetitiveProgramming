#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;

    if(n == 1) {
        cout << "1\n";
        return;
    }

    if(n == 2) {
        cout << "-1\n";
        return;
    }

    // assert(n >= 3);

    vector<ll> ans = {1, 2};
    for(ll i = 0; i < n - 2; i++) {
        ll x = (1LL << i) * 3LL;
        ans.push_back(x);
    }

    for(auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}
