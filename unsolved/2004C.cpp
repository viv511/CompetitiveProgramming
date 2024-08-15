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
	int n; cin >> n;
    int k; cin >> k;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        v[i] = a;
    }
    sort(v.begin(), v.end());

    int matchedElements = 1;
    int indexToMatch = 0;
    int maxElement = 0;

    if(n % 2 == 0) {
        indexToMatch = v.size()-2;
        maxElement = v[v.size()-1];
    }
    else {
        indexToMatch = v.size()-3;
        maxElement = v[v.size()-2];
    }

    while(k != 0 && indexToMatch >= 0) {
        sort(v.begin(), v.end());
        
        if(v[indexToMatch] == maxElement) {
            indexToMatch--;
        }
        else {
            v[indexToMatch]++;
            k--;
        }

    }

    sort(v.begin(), v.end());

    long long ans = 0;
    long long turn = 0;
    for(int i = v.size()-1; i >= 0; i--) {
        if(turn == 0) {
            ans += v[i];
            turn = 1;
        }
        else {
            ans -= v[i];
            turn = 0;
        }
    }

    cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}