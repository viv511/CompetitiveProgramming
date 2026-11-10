//2062A
#include <iostream>
#include <map>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        map<int, int> m;
        //x x O x x
        int a, b, d, e; cin >> a >> b >> d >> e;

        m[a+b]++;
        m[d-b]++;
        m[e-d]++;

        int ans = -1;
        for(auto a : m) {
            ans = max(ans, a.second);
        }
        
        cout << ans << "\n";
    }
}