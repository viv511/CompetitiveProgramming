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
#define yap(answer) cout << answer << "\n"

/*
3
5 1 1
10101
5 2 1
10101
6 3 2
000000

2
0
1
*/

void solve() {
    //Power = k, no consec spots > m
    int n, m, k; cin >> n >> m >> k;

    //Use a map to store all (len of gap, num of gap pairs)
    map<int, int> gaps;

    string spots; cin >> spots; //Binary String
    int curGapLen = 0;
    for(int i=0; i<n; i++) {
        if(spots[i] == '0') {
            curGapLen++;
        }
        else {
            if(curGapLen != 0) {
                gaps[curGapLen]++;
            }
            curGapLen = 0;
        }
    }
    if(curGapLen != 0) {
        gaps[curGapLen]++;
    }

    ll ans = 0;

    for(auto s : gaps) {
        //For each gap > m:
        if(s.fi >= m) {
            // s.fi = len of gap, size.se = num of gaps of size "size.fi"
            // Let gap size = s
            if(s.fi <= k) {
                //if s <= k, add 1 to the count
                ans += s.se * 1;
            }
            else {
                //Else: add s / (k+m-1) to the count (edge case if m == 1)
                if(m == 1) {
                    ans += s.se * ceil(s.fi / (double)k);
                }
                else {
                    ans += s.se * (s.fi / (k + m - 1));
                }
            }
        }
    }

    yap(ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}