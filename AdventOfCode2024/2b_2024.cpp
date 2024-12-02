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


    vector<int> tempArr(levels.size()-1);

    for(int i=0; i<levels.size(); i++) {
        bool okay = true;

        bool skip = false;
        for(int j=0; j<levels.size(); j++) {
            if(i == j) {
                skip = true;
                continue;
            }
            if(skip) {
                tempArr[j-1] = levels[j];
            }
            else {
                tempArr[j] = levels[j];
            }
        }
        
        //1 if increasing, -1 if decreasing
        int dir = tempArr[1]-tempArr[0];
        dir = abs(dir)/dir;

        for(int j=1; j<tempArr.size(); j++) {
            //See if its within 1 and 3 diff
            int diff = abs(tempArr[j]-tempArr[j-1]);
            if(diff < 1 || diff > 3) {
                okay = false;
            }

            //Check if same direction
            int currentDir = tempArr[j]-tempArr[j-1];
            currentDir = abs(currentDir)/currentDir;
            if(currentDir != dir) {
                okay = false;
            }
        }

        if(okay) {
            return true;
        }
    }

    return false;
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