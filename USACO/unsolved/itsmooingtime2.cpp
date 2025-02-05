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
    map<int, int> freq;
    vi distinct(n);

    set<int> s;
    for(int i=0; i<n; i++) {
        cin >> v[i];
        s.insert(v[i]);
        distinct[i] = s.size();
        freq[v[i]]++;
    }  

    ll ans = 0;
    
    map<int, int> m;
    for(int i=n-1; i>0; i--) {
        int num = v[i];
        m[num]++;

        if(m[num] == 2) { 
            ans += distinct[i-1];
            if(freq[num] > 2) {
                ans--;
            }
        }  
    }

    cout << ans << "\n";
}