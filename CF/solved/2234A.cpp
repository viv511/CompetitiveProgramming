#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    if (n <= 2) {
        sort(v.rbegin(), v.rend());
        for(int i=0; i<n; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    else {
        sort(v.rbegin(), v.rend());

        int x = v[0];
        int y = v[1];

        bool works = true;
        for(int i=2; i<n; i++) {
            int res = x % y;

            if(v[i] != res) {
                works = false;
                break;
            }
            else {
                x = y;
                y = v[i];
            }
        }

        if(works) {
            cout << v[0] << " " << v[1];
            cout << "\n";
        }
        else {
            cout << "-1\n";
        }
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
