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

	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;

	int ans = (n/sum);

	// cout << ans << "\n";

	int track = n - sum*ans;
	// cout << track << "\n";

	if(track == 0) {
		cout << 3*ans << "\n";
	}
	else {
		if(track-a <= 0) {
			cout << 3*ans + 1 << "\n";
		}
		else if(track-a-b <= 0) {
			cout << 3*ans + 2 << "\n";
		}
		else if(track-a-b-c <= 0) {
			cout << 3*ans + 3 << "\n";
		}
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