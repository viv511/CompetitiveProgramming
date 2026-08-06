#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int n0 = 0, n1 = 0;
    int delN = 0;

    for (char c : s) {
        if (c == '1') {
            n1++;
        }
        else {
            n0++;
        }
    }

    if (abs(n1 - n0) > 2) {
        cout << -1 << "\n";
        return;
    }
       
    int L = 1;
    int l0 = (s[0] == '0') ? 1 : 0;
    int l1 = (s[0] == '1') ? 1 : 0;

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) {
            L++;
            if (s[i] == '0') {
                l0++;
            }
            else {
                l1++;
            }
        }
    }
        
    cout << (n - L) + max(0, abs((n0 - n1) - (l0 - l1)) - 1) << "\n";
}  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}