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
#define fi first
#define se second
#define pb push_back
#define ins insert
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

void solve() {
	ll k, x; cin >> k >> x;

    ll ans = 0;
    ll days = 0;
    for(int i=1; i<=k; i++) {
        if(days >= x) break;
        days += i;
        ans++;
    }
    for(int i=k-1; i>=1; i--) {
        if(days >= x) break;
        days += i;
        ans++;
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