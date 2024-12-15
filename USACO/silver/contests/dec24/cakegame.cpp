


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)(x.size())

void solve() {
	int n; cin >> n;

	vector<ll> cakes(n);
	vector<ll> prefix(n+1, 0);
	ll totalSize = 0;

	for (int i = 0; i < n; i++) {
		cin >> cakes[i];
		totalSize += cakes[i];
		prefix[i+1] = prefix[i] + cakes[i];
	}

	ll turnCount = (n / 2) - 1;
	ll stashSize = 0;

	//Take the turnCount # of biggest cakes from the ends of the array (unsorted)

	int leftPointer = 0;
	int rightPointer = sz(cakes)-1;
	while(turnCount--) {
		//Look at two ahead and two behind
		if(prefix[leftPointer+2] > (prefix[rightPointer+1] - prefix[rightPointer-1])) {
			stashSize += cakes[leftPointer];
			leftPointer++;
		} else {
			stashSize += cakes[rightPointer];
			rightPointer--;
		}

	}

	//Subtract remaining for Bessie
	cout << totalSize - stashSize << " " << stashSize << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}