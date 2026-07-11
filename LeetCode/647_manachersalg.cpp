#include <string>
#include <vector>
using namespace std;

//#'s between so that we can make any even pali an odd pali
string insertHashtags(const string& s) {
    string res = "^#";
    for(int i=0; i<s.length(); i++) {
        res += s[i];
        res += "#";
    }
    res += "$";

    return res;
}

int countSubstrings(string s) {
    int ans = 0;

    string newS = insertHashtags(s);

    int n = newS.size();
    vector<int> pos(n, 0);

    int c = 0;
    int r = 0;

    for(int i = 1; i < n - 1; i++) {
        int mirror = 2 * c - i;

        if(i < r) {
            pos[i] = min(pos[mirror], r - i);
        }

        while(newS[i + pos[i] + 1] == newS[i - pos[i] - 1]) {
            pos[i]++;
        }

        if(i + pos[i] > r) {
            c = i;
            r = i + pos[i];
        }

        // e.x. abcba -> pos[i] = 5 and thus 3 palis: abcba, bcb, c
        ans += (pos[i] + 1) / 2;
    }

    return ans;
}