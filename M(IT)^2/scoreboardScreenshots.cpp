#include <iostream>
#include <new>
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
#define yap(answer) cout << answer << endl;
#define vyap(v) for (auto &vv : v) cout << vv << " "; cout << endl;


bool sorter(const pair<int, vector<int>> a, const pair<int, vector<int>> b) {
	int direction = 0;
	
	for (int i = 0; i < (int)a.second.size(); i++) {
		int inner = a.second[i] == b.second[i] ? 0 : (a.second[i] < b.second[i] ? 1 : -1);
		if (direction == 0) direction = inner;
		else {
			if (direction != inner && inner != 0) {
				throw bad_array_new_length();
			}
		}
	}

	return direction == 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector< pair < int, vector <int> > > screenshots;
	for (int i = 0; i < n; i++) {
		vector<int> teams((int)k);
		for (int j = 0; j < k; j++) {
			cin >> teams[j];
		}
		screenshots.push_back(make_pair(i + 1, teams));
	}

	// check to see if it works
	try {
	sort(screenshots.begin(), screenshots.end(), sorter);
		cout << "YES" << endl;
		for (auto &ss : screenshots) {
			cout << ss.first << " ";
		}
		cout << endl;
	} catch (bad_array_new_length &e) {
		cout << "NO" << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// int T; cin >> T;
	// while(T--) {
	// 	solve();
	// }
	solve();
}