#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define ins insert

#define yap(answer) cout << answer << "\n"


void solve() {
	int n; cin >> n;
    vi s;

    vi v;
    for(int i=0; i<n; i++) {
        int a; cin >> a;
        v.pb(a);
    }

    s.pb(v[0]);
    s.pb(1440-v[n-1]);

    for(int i=1; i<n; i++) {
        s.pb(v[i]-v[i-1]);
    }

    int ans = 0;

    //check how many values in s are greater than 120
    for(auto a : s) {
        if(a >= 120) {
            ans += ((int)a / 120);
        }
    }

    if(ans >= 2) {
        yap("YES");
    } else {
        yap("NO");
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