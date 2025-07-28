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

void solve() {
	int n; cin >> n;
    vi v(n);
    vi o(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
        o[i] = v[i];
    }
    
    string s; cin >> s;
    //sample string 01110
    //sort the segments of the strings with 1 --> in v

    for(int i=0; i<n-1; i++) {
        if(s[i] == '1') {
            int j = i;
            while(j < n-1 && s[j] == '1') {
                j++;
            }
           
            sort(v.begin() + i, v.begin() + j+1);
            i = j - 1;
        }
    }


    sort(all(o));

    // for(auto a : o) {
    //     cout << a << " ";
    // }
    // yap(" ");
    // for(auto a : v) {
    //     cout << a << " ";
    // }


    for(int i=0; i<n; i++) {
        if(v[i] == o[i]) {
            continue;
        }
        else {
            yap("NO");
            return;
        }
    }
    
    yap("YES");
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T = 1;
	while(T--) {
		solve();
	}
}