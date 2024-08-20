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
    vector<int> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    //Find most repeated element
    int mostRepeated = 0;
    int count = 0;
    int maxCount = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0 || a[i] == a[i-1]) {
            count++;
        } else {
            if(count > maxCount) {
                maxCount = count;
                mostRepeated = a[i-1];
            }
            count = 1;
        }
    }

    maxCount = max(maxCount, count);

    cout << n-maxCount << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}