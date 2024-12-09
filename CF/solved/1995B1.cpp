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

typedef vector<ll> vi;
typedef pair<ll, ll> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())
#define print(answer) cout << answer << "\n"

void solve() {
    ll n; ll m;
    cin >> n >> m;

    vi v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(all(v));

    ll ans = 0;

    for (ll i = 0; i < n;) {
        ll j = i;
        while (v[j] == v[i]) {
            j++;
        }

        ll l = j;
        while (v[l] == v[i] + 1) {
            l++;
        }

        for (ll c = 0; c <= j - i; c++) {
            if (c * v[i] > m) {
                continue;
            }

            ll val = c * v[i];
            ll t = min((m - val) / (v[i] + 1), l - j);

            val += t * (v[i] + 1);
            ans = max(ans, val);
        }

        i = j;
    }

    print(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}
