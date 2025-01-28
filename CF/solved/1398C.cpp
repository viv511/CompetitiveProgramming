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
	ll n; cin >> n;
    string s; cin >> s;

    vector<ll> pref(n+1, 0);
    for(int i=0; i<n; i++) {
        ll num = s[i] - '0';
        pref[i+1] = pref[i] + num;
    }

    ll ans = 0;

    //j - i = pref[j] - pref[i]
    //pref[j] - j = pref[i] - i

    //ans is when pref[x] - x = pref[y] - y
    map<ll, ll> m;

    for(int i=0; i<=n; i++) {
        m[pref[i] - i]++;
    }

    //Loop through the map and calculate the answer
    for(auto a : m) {
        ll x = a.se; //1 + 2 + 3 .. x-1
        //2 --> 1
        //3 --> 3 = 1 + 2
        //4 --> 6 = 1 + 2 + 3
        ans += x * (x-1) / 2ll;
    }

    yap(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}