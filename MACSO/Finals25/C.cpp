#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define ins insert
#define all(v) v.begin(), v.end()

#define yap(answer) cout << answer << "\n"

//sum every subsequence
int result(int left, int right, vector<int> nums) {
    
    int curAns = 0;
    int maxAns = -1e9;

    for (int i = left; i <= right; i++) {
        curAns = 0;
        for (int j = i; j <= right; j++) {
            curAns += nums[j];
            maxAns = max(maxAns, curAns);
        }
    }

    return maxAns;
}

void solve() {
	int n; cin >> n;

    vi v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    int ans = -1e9;

    int j = 0;
    for(int i=0; i<n-1; i++) {
        if(abs(v[i] % 10) == abs(v[i+1] % 10)) {
            ans = max(ans, result(j, i, v));
            j = i+1;
        }
    }

    ans = max(ans, result(j, n-1, v));
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