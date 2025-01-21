//https://leetcode.com/problems/bulls-and-cows/
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
#define pb push_back
#define all(v) v.begin(), v.end()

class Solution {
public:

    string getHint(string secret, string guess) {
        vi s(10, 0);
        vi g(10, 0);

        int bulls = 0;
        int cows = 0;

        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
            else {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        for(int i=0; i<s.size(); i++) {
            if(s[i] > 0 && g[i] > 0) {
                cows += min(s[i], g[i]);
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};