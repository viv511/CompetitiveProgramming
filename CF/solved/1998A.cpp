#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

void solve() {
    int x, y, k; cin >> x >> y >> k;

    vector<pair<int, int>> ans;

    if(k%2 == 0) {
        k /= 2;
        for(int i=x-k; i<=x+k; i++) {
            if(i == x) continue;
            ans.push_back(make_pair(i, 0));
        }
        for(int i=y-k; i<=y+k+1; i++) {
            if(i == y) {
                k--;
                continue;
            }
            ans[i-y+k].second = i;
            // cout << i - y + k << " ";
        }
    }
    else {
        k--;
        k /= 2;
        for(int i=x-k; i<=x+k; i++) {
            ans.push_back(make_pair(i, 0));
        }
        for(int i=y-k; i<=y+k; i++) {
            ans[i-y+k].second = i;
        }
    }

    for(auto a : ans) {
        cout << a.first << " " << a.second << "\n";
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