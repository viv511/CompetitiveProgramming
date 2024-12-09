#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    bool board[n][m];

    bool flip = true;
    bool even = false;
    if(m % 2 == 0) {
        even = true;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            char a; cin >> a;
            if(a == '.') {
                board[i][j] = true;
                if(flip) {
                    cout << "B";
                }
                else {
                    cout << "W";
                }
            }
            else {
                board[i][j] = false;
                cout << "-";
            }
            flip = !flip;
        }
        cout << "\n";
        if(even) {
            flip = !flip;
        }

    }

}