//https://codeforces.com/problemset/problem/2038/A

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
	int n, k; cin >> n >> k;

    vi a(n);
    F0R(i, n) cin >> a[i];

    vi b(n);
    F0R(i, n) cin >> b[i];

    vi hourLimits(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        hourLimits[i] = a[i]/b[i]; //Note that int conversion automatically applies floor
        sum += hourLimits[i];
    }

    if(sum < k) {
        F0R(i, n) {
            cout << "0 ";
        }
        cout << "\n";
        return;
    }

    //last worker will work min(k, a[i]/b[i]) hours
    vi ans(n, 0);
    ans[n-1] = min(k, hourLimits[n-1]);
    k -= ans[n-1];

    //for the rest of the workers, we will try to maximize the number of hours they work
    for(int i=n-2; i>=0; i--) {
        if(k == 0) {
            break;
        }

        ans[i] = min(k, hourLimits[i]);
        k -= ans[i];
    }

    F0R(i, n) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}