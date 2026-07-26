#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <map>

typedef long long ll;

using namespace std;

void solve() {
	ll n; cin >> n;
	vector<ll> v(n);
	
	for(int i=0; i<n; i++) {
        cin >> v[i];
    }

    int m; cin >> m;
    vector<string> match(m);

    for(int i=0; i<m; i++) {
        cin >> match[i];
    }

    //Map from number --> letter
   
    for(int numStr = 0; numStr < m; numStr++) {
        // cout << "--\n";

        if(n != match[numStr].length()) {
            cout << "NO\n";
            continue;
        }

        map<char, ll> charMap;
        map<ll, char> numMap;

        bool solved = false;

        for(int i=0; i<n; i++) {
            if(solved) {
                break;
            }

            char letter = match[numStr][i];
            char num = v[i];

            if(charMap.find(letter) == charMap.end()) {
                charMap[letter] = num;
            }
            else {
                if(charMap[letter] != num) {
                    cout << "NO\n";
                    solved = true;
                    break;
                } 
            }

            if(solved) {
                break;
            }

            if(numMap.find(num) == numMap.end()) {
                numMap[num] = letter;
            }
            else {
                if(numMap[num] != letter) {
                    cout << "NO\n";
                    solved = true;
                    break;
                }
            }
        }
        
        if(solved) {
            continue;
        }
        else {
            cout << "YES\n";
        }

        numMap.clear();
        charMap.clear();
    }
    

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		solve();
	}
}