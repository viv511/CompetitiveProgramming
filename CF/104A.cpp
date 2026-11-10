#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n; cin >> n;

    if(n <= 10) {
        cout << 0 << "\n";
    }
    else {
        n -= 10;

        if(n == 10) {
            cout << 15 << "\n";
        }
        else if(n <= 11) {
            cout << 4 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }   
}