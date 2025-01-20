#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull; 
typedef vector<int> vi;
typedef pair<int, int> pi;

#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sz(x) (int)(x.size())
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) FOR(i, 0, a)
#define yap(answer) cout << answer << "\n"

void solve() {
	int n; cin >> n;
	
	map<int, bool> nums;

	int q; cin >> q;	
	for(int i=0; i<n; i++) {
		nums[i] = false;
	}

	vi list(n);
	for(int i=0; i<n; i++) {
		int a; cin >> a;
		nums[a] = true;
		list[i] = a;
	}

	while(q--) {
		int type; cin >> type;

		if(type == 1) {
			int index, value; cin >> index >> value;

			nums[list[index-1]] = false; // turn off the value "frees it up"
			nums[value] = true; //add the value

			list[index-1] = value;
		}
		else if(type == 2) {
			int l, r; cin >> l >> r;
			l--;
			r--; //0-based indexing, but we don't need

            if(n <= 2000 && q <= 2000) {
                set<int> s;
                for(int i=l; i<=r; i++) {
                    s.insert(list[i]);
                }

                int ans = 1;
                while(s.find(ans) != s.end()) {
                    ans++;
                }

                yap(ans);
            }
            else {
                for(int i=n-1; i>=0; i--) {
                    if(nums[i+1] == false) {
                        yap(i+1);
                        break;
                    }
                }
            }

		}
	
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}

