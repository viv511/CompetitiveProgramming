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

	std::map<int, int> vals;

	for(int i=0; i<2*n; i++) {
		int a; cin >> a;
		vals[a]++;
	}

	int ans = 0;
	for(auto pair : vals) {
		if(pair.second % 2 == 1) {
			ans++; 
		}
	}

	yap(ans / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}