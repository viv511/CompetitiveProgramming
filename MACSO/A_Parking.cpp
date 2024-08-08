#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

	int ans = n*m;
	if(ans % 2 == 1) {
		ans--;
	}

	cout << ans / 2;
}
