#include <iostream>

using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    bool isTwo = false;
    int ans = 0;

    // blocked = "#", empty = "."
    // track the chains of empty cells in open

    for (int i = 0; i < n; i++) {
        if (i >= 2) {
            if (s[i] == '.' && s[i - 1] == '.' && s[i - 2] == '.') {
                isTwo = true;
            }
        }

        if (s[i] == '.') {
            ans++;
        }
    }

    if (isTwo) {
        cout << 2 << "\n";
    } else {
        cout << ans << "\n";
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