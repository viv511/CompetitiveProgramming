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

void solve() {
	string s1, s2; cin >> s1 >> s2;

	vi bBefore;
	vi bAfter;

	for(int i=0; i<s1.length(); i++) {
		if(s1[i] == 'B') {
			bBefore.pb(i);
		}
	}

	for(int i=0; i<s2.length(); i++) {
		if(s2[i] == 'B') {
			bAfter.pb(i);
		}
	}

	int ans = 0;

	if(bBefore.size() != bAfter.size()) {
		yap(-1);
		return;
	}

	sort(all(bBefore));
    sort(all(bAfter));

	for(int i=0; i<bBefore.size(); i++) {
        ans += abs(bBefore[i] - bAfter[i]);
	}

    if(ans % 2 != 0) {
        yap(-1);
        return;
    }

    yap(ans / 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}