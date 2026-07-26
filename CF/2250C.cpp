#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void solve() {
    // ranks seem to be like the opposite diagonal on a square matrix
    // 1 n, 2 n-1, 3 n-2, ..., n 1

    int n; cin >> n;
    vi l, r, u, v;

    for (int i = 0; i < n; i++) {
        int li, ri, ui, vi; cin >> li >> ri >> ui >> vi;
        l.push_back(li);
        r.push_back(ri);
        u.push_back(ui);
        v.push_back(vi);
    }

    // greedy doesnt work because its not optimal always
    // int res = 0;

    // for (int m = 1; m <= n; m++) {
    //     // fix m and check, want biggest m == longest subseq

    //     int j = 1;

    //     for (int i = 0; i < n; i++) {
    //         bool okLeft = (j < l[i] || j > r[i]);
    //         int right = m - j + 1;
    //         bool okRight = (right < u[i] || right > v[i]);

    //         if (okLeft && okRight) {
    //             j++;
    //         }
    //     }

    //     if (j - 1 == m) {
    //         res = max(res, m);
    //     }
    // }

    // cout << res << "\n";


    // dp could work, n <= 5000

    // sort of like an NFA lmao shout out 251
    // transition is either skip the element or move to next state
    // if we only use one dp array we are modifying what we iterate over --> bugs

    int res = 0;

    vector<int> dp(n + 1, -1);
    dp[0] = 0;   

    for (int i = 0; i < n; i++) {
        vector<int> dp_2 = dp;

        for (int m = 0; m < n; m++) {
            if (dp[m] == -1) continue;

            int lRank = dp[m] + 1; // j
            int rRank = m - dp[m];
            
            if (lRank >= l[i] && lRank <= r[i]) continue;
            if (rRank >= u[i] && rRank <= v[i]) continue;      
            
            dp_2[m + 1] = max(dp_2[m], lRank);
        }

        dp = dp_2;
    }

    for (int m = 0; m <= n; m++) {
        if (dp[m] == m) {
            res = max(res, m);
        }
    }


    cout << res << "\n";
}   

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}