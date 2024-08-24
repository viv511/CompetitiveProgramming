#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    string s;
    cin >> s;

    int commonDenominator = 1;
    vector<pair<int, int>> fractions;

    if(s.length() % 4 != 0) {
        s = "+" + s;
    }

    for(int i=0; i<s.length(); i++) {
        if(s[i] == '+' || s[i] == '-') {
            int sign = (s[0] == '+') ? 1 : -1;

            string frac = s.substr(0, 4);
            int numerator = frac[1]-'0';
            int denominator = frac[3]-'0';

            numerator *= sign;

            commonDenominator = lcm(denominator, commonDenominator);
            fractions.push_back(make_pair(numerator, denominator));
            s = s.substr(4);
        }
    }
    
    int dir = (s[0] == '+') ? 1 : -1;
    int n = s[1]-'0';
    int d = s[3]-'0';
    n *= dir;

    commonDenominator = lcm(d, commonDenominator);
    fractions.push_back(make_pair(n, d));

    long long sum = 0;
    for (const auto& frac : fractions) {
        int numerator = frac.first;
        int denominator = frac.second;

        // cout << numerator << " " << denominator << "\n";

        int ratio = commonDenominator / denominator;
        sum += numerator * ratio;
    }

    int finalRatio = gcd(abs(sum), commonDenominator);

    sum /= finalRatio;
    commonDenominator /= finalRatio;

    string ans = to_string(sum) + "/" + to_string(commonDenominator);
    cout << ans;
}
