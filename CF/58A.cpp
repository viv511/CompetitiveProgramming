#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <queue>

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
 
typedef vector<int> vi;
typedef pair<int, int> pi;
#define all(v) v.begin(), v.end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ins insert
#define sq(x) ((x) * (x))
#define sz(x) (int)(x.size())
#define print(answer) cout << answer << "\n"


int main() {
    string s;
    cin >> s;

    string check = "hello";
    int counter = 0;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == check[counter]) {
            counter++;
        }
    }


    if(counter >= 5) {
        print("YES");
    }
    else {
        print("NO");
    }
}

