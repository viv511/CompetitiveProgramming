//2062A
#include <iostream>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s; cin >> s;
        int ans = 0;
        for(auto a : s) {
            if(a-'0') ans++;
        }
        cout << ans << "\n";
    }
}