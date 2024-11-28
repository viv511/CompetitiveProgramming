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

using namespace std;

void solve() {
	int n; cin >> n;
	vi v(n);

	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	for(int k=1; k<n; k++) {
		bool works = true;
		int index = k;
		int prev = v[0];

		for(int i=1; i<n; i++) {
			if(v[index] < prev) {
				works = false;
				break;
			}

			prev = v[index];

			index += k;
			index %= n;
		}

		if(works) {
			yap(k);
			return;
		}
	}

	yap(-1);
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}