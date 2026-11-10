#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

void solve() {
	int n; cin >> n;

	vi a(n);
	vi b(n);

	F0R(i, n) {
		cin >> a[i];
	}

	F0R(i, n) {
		cin >> b[i];
	}

	int ans = 0;
	ans += a[sz(a)-1];

	for(int i=0; i<sz(a)-1; i++) {
		if(a[i]-b[i+1] > 0) {
			ans += a[i]-b[i+1];
		}
		// cout << a[i] << " ";
	}
	cout << ans << "\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}