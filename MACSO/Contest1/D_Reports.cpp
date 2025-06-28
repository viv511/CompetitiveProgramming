#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	vector<int> v(n);

	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	int q; cin >> q;
	while(q--) {
		char a; cin >> a;
		if(a == 'm') {
			int l, r; cin >> l >> r;

			int ans = -1;
			for(int i=l-1; i<=r-1; i++) {
				ans = max(ans, v[i]);
			}

			cout << ans << "\n";
		}
		else {
			int l, r; cin >> l >> r;
			int increase; cin >> increase;

			for(int i=l-1; i<=r-1; i++) {
				v[i] += increase;
			}


		}


	}
}
