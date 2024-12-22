#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

void solve() {
	int n, k; cin >> n >> k;

	vi a(n);
	vi b(n);

	F0R(i, n) {
		cin >> a[i];
	}

	F0R(i, n) {
		cin >> b[i];
	}

	int maxRevenue = 0;
	int currentRev = 0;
	int p = 1;
	bool failed = false;
	int negReviews = 0;

	while(failed == false && p <= *max_element(b.begin(), b.end())) {
		currentRev = 0;
		negReviews = 0;

		for(int i=0; i<n; i++) {
			if(p <= a[i]) {
				currentRev += p;
			}
			else if(p > a[i] && p <= b[i]) {
				currentRev += p;
				negReviews++; //Buy, but give a bad review
			}
		}

		//If badReviews > k, then we cant set this price so exit before setting maxRev
		if(negReviews > k) {
			failed = true;
			break;
		}

		maxRevenue = max(maxRevenue, currentRev);
		p++;
	}


	cout << maxRevenue << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}