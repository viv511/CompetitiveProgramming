#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
    
    sort(v.begin(), v.end());

    cout << min(v[2]-v[1], v[1]-v[0]) << "\n";
}  

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}