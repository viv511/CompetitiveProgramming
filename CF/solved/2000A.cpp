#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solve() {
	string s; cin >> s;

    if(s.length() <= 2) {
        cout << "NO\n";
    }
    else {
        if(s.substr(0, 2) == "10") {
            if(s.substr(2) != "1" && s.substr(2)[0] != '0') {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            cout << "NO\n";
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
