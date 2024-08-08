#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> llvector;
typedef vector<llvector> Matrix;
typedef vector<Matrix> DP_Table;

int main() {
    int n, m, k; cin >> n >> m >> k;

    //Fence problem, need to increase by 1 both
    n++;
    m++;

    //Try a DP approach? use [n][m][k] to store values
    //Weird af but trust lmao
    DP_Table dp(n, Matrix(m, llvector(k + 1, 0)));
    
    //Base case to start
    dp[0][0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int diag = 0; diag <= k; diag++) {

                if (i > 0) {
                    dp[i][j][diag] += dp[i-1][j][diag];
                }
                
                if (j > 0) {
                    dp[i][j][diag] += dp[i][j-1][diag];
                }
                
                if (i > 0 && j > 0 && diag > 0) {
                    dp[i][j][diag] += dp[i-1][j-1][diag-1]; //SUBTRACT HERE!!
                }
            }
        }
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         for (int diag = 0; diag <= k; diag++) {
    //             cout << dp[i][j][diag] << " ";
    //         }
    //     }
    //     cout << "\n";
    // }


    //Backtrack and find ans
    long long ans = 0;
    for(int diag = 0; diag <= k; diag++) {
        ans += dp[n-1][m-1][diag];
    }

    cout << ans;
}