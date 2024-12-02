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
#define sz(x) (int)(x.size())
#define yap(answer) cout << answer << "\n"

bool checkSafety(string r) {
    vector<int> levels;

    while(r.find(" ") != std::string::npos) {
        levels.push_back(stoi(r.substr(0, r.find(" "))));

        r = r.substr(r.find(" ") + 1);
    }

    levels.push_back(stoi(r));

    bool okay = true;

    //1 if increasing, -1 if decreasing
    int dir = levels[1]-levels[0];
    dir = abs(dir)/dir;

    for(int i=1; i<levels.size(); i++) {
        //See if its within 1 and 3 diff
        int diff = abs(levels[i]-levels[i-1]);
        if(diff < 1 || diff > 3) {
            okay = false;
        }

        //Check if same direction
        int currentDir = levels[i]-levels[i-1];
        currentDir = abs(currentDir)/currentDir;
        if(currentDir != dir) {
            okay = false;
        }

        if(okay == false) {
            break;
        }
    }

    return okay;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long ans = 0;
    int n = 1000;

    for(int i=0; i<n; i++) {
        string report;
        getline(cin, report);

        ans += checkSafety(report);
    }

    yap(ans);
}