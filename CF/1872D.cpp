
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

void solve() {
	ll n, x, y;
	cin >> n >> x >> y;

	if(x == y) {
		cout << "0\n";
		return;
	}

	ll xNum = n / x;
	ll yNum = n / y;
	ll bottomVal = n-xNum+1;

	ll xSum = (bottomVal + n) * xNum / 2;

	ll bigger = lcm(x, y);
	ll intersections = n / bigger;

	// cout << xNum << " " << yNum << " " << intersections << " ";

	ll intersectSum = (2 * bottomVal + intersections - 1) * intersections / 2;

	ll yCnt = yNum - intersections;

	ll ySum = -1;
	if (yNum + xNum - intersections > n) {
		ySum = (1 + yNum) * (yNum) / 2;
	} else {
		ySum = (yNum - intersections + 1) * (yNum - intersections) / 2 + intersectSum;
	}

	ll ans = xSum - ySum;
	cout << ans << '\n';
}


int main() {
	int T; 
	cin >> T;

	while(T--) {
		solve();
	}	
}	
