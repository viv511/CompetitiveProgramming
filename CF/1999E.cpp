#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //Pre-computation!!
	vector<int> powers;
	for(int i=0; i<15; i++) {
		powers.push_back(pow(3, i));
	}

	int curPower = 1;
	vector<int> arr(200005);
	for(int i=1; i <= arr.size()-1; i++) {
		if(i == powers[curPower]) {
			curPower++;
		}

		arr[i] = curPower;
	}

	int T; cin >> T;
    
	while(T--) {
		int l, r; cin >> l >> r;

		int ans = 2*arr[l];

		for(int i=l+1; i<=r; i++) {
			ans += arr[i];
		}

		cout << ans << "\n";
	}
}