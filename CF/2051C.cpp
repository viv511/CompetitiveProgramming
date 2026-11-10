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
typedef vector<int> vi;

#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)

void solve() {
	int n; cin >> n;
	int m, k; cin >> m >> k;

    vi lists(m);

    F0R(i, m) {
        cin >> lists[i];
    }

    map<int, bool> ans;

    F0R(i, k) {
        int a; cin >> a;
        ans.insert(make_pair(a, true));
    }

    if(n == k) { //all ans
        F0R(i, m) {
            cout << "1";
        }
        cout << "\n";
    }
    else if((n-1) > k) { //if # you dont know is more than # you know
         F0R(i, m) {
            cout << "0";
        }
        cout << "\n";
    }
    else {
        F0R(i, m) {
            if(ans.find(lists[i]) != ans.end()) {
                cout << "0";
            }
            else {
                cout << "1";
            }
        }
        cout << "\n";
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