#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);

    cin >> v[0];

    for(int i=1; i<n; i++) {
        v[i] = v[i-1];

        int b; cin >> b;
        v[i] += b;
    }

    long long ans = 0;
    string s; cin >> s;
    bool set = true;

    // for(auto a : v) {
    //     cout << a << " ";
    // }

    while(set) {
        //Find first L
        int start = s.length();
        //Find last R
        int end = 0;

        for(int i=0; i < s.length(); i++) {
            if(s[i] == 'L') {
                start = i;
                break;
            }
        }

        for(int i = s.length()-1; i >= 0; i--) {
            if(s[i] == 'R') {
                end = i;
                break;
            }
        }

        if(end > start) {
            if(start == 0) {
                ans += v[end];
            }
            else {
                ans += v[end]-v[start-1];
            }
           

            s[start] = '.';
            s[end] = '.';
        }
        else {
            set = false;
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        solve();
    }
}
