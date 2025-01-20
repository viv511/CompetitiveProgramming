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
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define yap(answer) cout << answer << "\n"

void solve() {
	double m;
	cin >> m;

	// double l = log(m) / log(5);

	// int time = (double)(int)l == l ? int(l) : ceil(l);
	int c = 1;
	while (m > 5) {
		c++;
		m /= 5;
	}
	cout << "MIT";
	if (c > 1) cout << "^" << c;
	cout << " time" << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}