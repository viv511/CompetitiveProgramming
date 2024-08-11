#include <iostream>
#include <string>
using namespace std;

void solve() {
    int ans = 0;
	string s; cin >> s;
    for(int i=0; i<s.length(); i++) {
        ans += s[i]-'0';
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