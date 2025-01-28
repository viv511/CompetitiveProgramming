#include <iostream>
using namespace std;

int main() {

    int a, b; cin >> a >> b;
    int k1, k2; cin >> k1 >> k2;

    if(k1 > k2) {
        int temp = k1;
        k1 = k2;
        k2 = temp;

        temp = a;
        a = b;
        b = temp;
    }

    int cards; cin >> cards;

    int smallest = (a)*(k1-1) + (b)*(k2-1);

    if(cards <= smallest) {
        cout << 0 << " ";
    }
    else {
        cout << cards-smallest << " ";
    }

    int ans = 0;
   
    if(cards <= k1 * a) {
        cout << (int)(cards / k1);
    }
    else {
        int ans = a + (cards - (k1 * a)) / k2;
        cout << ans;
    }

    cout << "\n";

}