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
	int k; cin >> k;

	map<ll, bool> trees;

	ll lowest = 1e9 + 20;
	ll highest = -1;
	for(int i = 0; i < n; i++) {
		int tree; cin >> tree;
		tree += 10e9; //Shift to 0 - 2*10^9

		if(tree < lowest) {
			lowest = tree;
		}
		
		if(tree > highest) {
			highest = tree;
		}
	
		trees[tree] = true;
	}

	vector<ll> prefixTrees(highest-lowest+1, 1);
	for(int i = lowest; i <= highest; i++) {
		if(i == lowest) {
			continue;
		}

		prefixTrees[i] = prefixTrees[i-1];

		if(trees[i]) {
			prefixTrees[i]++;
		}
	}

	for(auto a : prefixTrees) {
		cout << a << " ";
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