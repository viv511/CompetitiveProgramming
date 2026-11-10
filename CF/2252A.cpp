#include <iostream>
#include <map>

using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> m;
    long long score = 0;    

    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        m[a]++;
        score += a;
    }

    int maxCount = 0;
    int maxVal = 0;
    for (auto e : m) {
        if (e.second > maxCount) {
            maxCount = e.second;
            maxVal = e.first;
        }
    }

    int rest = n - maxCount;

    if (maxCount <= rest + 1) {
        cout << score << "\n";
    }
    else {
        long long a = maxCount * maxVal;
        long long b = (rest + 2) * maxVal;
        cout << score - a + b << '\n';
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