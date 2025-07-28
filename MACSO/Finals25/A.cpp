#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    long double a, b, c;
    cin >> a >> b >> c;

    long double disc = sqrt(b*b - 4.0*a*c);
    
    if(disc == 0) {
        cout << -b / (2.0 * a) << "\n";
    }
    else {
        long double root1 = (-b + disc) / (2.0 * a);
        long double root2 = (-b - disc) / (2.0 * a);
        
        cout << min(root1, root2) << " " << max(root1, root2) << "\n";
    }
}