//2061A
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int numEven = 0;
        int numOdd = 0;

        for(int i=0; i<n; i++) {
            int x; cin >> x;
            if(x%2==0) {
                numEven++;
            }
            else {
                numOdd++;
            }
        }

        if(numEven) {
            cout << numOdd+1 << "\n";
        }
        else {
            cout << numOdd-1 << "\n";
        }
        
    }
}