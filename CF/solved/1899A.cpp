#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    ll n; cin >> n;

    if (n % 3 == 0) {
        cout << "Second\n";
    } else {
        cout << "First\n";
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