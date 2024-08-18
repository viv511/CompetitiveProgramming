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

void solve() {
    int n; cin >> n;

    bool allEven = true;
    bool allOdd = true;
    ll biggestOdd = -1;
    vector<int> evens;

    for(int i=0; i<n; i++) {
        int a; cin >> a;

        if(a % 2 == 0) {
            allOdd = false;
            evens.push_back(a);
        }
        else {
            allEven = false;
            biggestOdd = max((int)biggestOdd, a);
        }
    }

    sort(evens.begin(), evens.end());

    if(allEven || allOdd) {
        cout << "0\n";
    }
    else {
        int ans = 0;
        int bigger = 0;
        for(int i=0; i<evens.size(); i++) {
            if(evens[i] < biggestOdd) {
                biggestOdd += evens[i];
                ans++;
            }
            else {
                bigger++;
            }
        }

        if(bigger == 0) {
            cout << ans << "\n";
        }
        else {
            cout << ans + bigger + 1 << "\n";
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