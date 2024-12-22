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

	vector<ll> cakes(n);
	vector<ll> prefix(n+1, 0);
	ll totalSize = 0;

	F0R(i, n) {
		cin >> cakes[i];
		totalSize += cakes[i];
		prefix[i+1] = prefix[i] + cakes[i];
	}

	ll turnCount = (n / 2) - 1;
	ll elsieBestScore = -1;

	F0R(i, turnCount+1) {
		ll leftSum = prefix[i]-prefix[0];
		ll rightSum = prefix[n] - prefix[n-(turnCount-i)];

		elsieBestScore = max(elsieBestScore, leftSum + rightSum);
	}

	ll bessieBestScore = totalSize - elsieBestScore;
	cout << bessieBestScore << " " << elsieBestScore << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}