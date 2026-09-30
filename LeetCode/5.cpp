#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
   // solve this with a dp approach
   // have o(n^2) subproblems, have dp[i,j] mean that substring from index i to j is a palindrome

   // dp[i][j]
   // = true if i = j
   // = (s[i] == s[j]) && dp[i+1][j-1]

   int n = s.length();
   vector<vector<bool>> dp(n, vector<bool>(n, false));

   int maxIndex = 0, maxLen = 1;

   // base case:
   for (int i = 0; i < n; i++) {
      dp[i][i] = true;
   }

   // recurrence:
   for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
         int j = i + len - 1;

         if ((s[i] == s[j]) && (len == 2 || dp[i + 1][j - 1])) {
            dp[i][j] = true;

            if (len > maxLen) {
               maxLen = len;
               maxIndex = i;
            }
         }
      }
   }

   return s.substr(maxIndex, maxLen);
}