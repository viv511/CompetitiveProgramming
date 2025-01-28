#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    int n; cin >> n;
    vi v(n);

    for(int i=0; i<n; i++) {
        cin >> v[i];
    }  

    map<int, int> m;
    ll ans = 0;
    set<int> s;

    for(int i=n-1; i>=0; i--) {
        int num = v[i];
        m[num]++;

        if(m[num] == 2) { //two occurances --> search for distinct nums
            for(int j=0; j<i; j++) {
                if(v[j] != num) {
                    s.insert(v[j]);
                }
            }

            ans += s.size();
            s.clear();
        }  
    }

    cout << ans << "\n";
}