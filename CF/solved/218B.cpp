/*
4 3
2 1 1
*/

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
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())
#define print(answer) cout << answer << "\n"

using namespace std;

void solve() {
	int n, p;
    cin >> n >> p;

    vi big(p);
    vi small(p);
    for (int i = 0; i < p; i++) {
        cin >> big[i];
        small[i] = big[i];
    }


    int maxCount = 0;
    int maxAns = 0;
    while(maxCount < n) {
        sort(all(big));

        maxAns += big[p-1];  
        big[p-1]--; 

        maxCount++;   
    }

    int minCount = 0;
    int minAns = 0;
    while(minCount < n) {
        sort(all(small));
        minAns += small[0];   
        small[0]--; 
        if(small[0] == 0) {
            small.erase(small.begin());
        }
        minCount++;   
    }

    cout << maxAns << " " << minAns << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}