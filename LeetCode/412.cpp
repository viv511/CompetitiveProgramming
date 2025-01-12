//https://leetcode.com/problems/fizz-buzz/description/

#include <iostream>
#include <vector>

using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> v;
    for(int i=1; i<=n; i++) {
        string ans = "";
        if(i%3 == 0 && i%5 == 0) {
            ans += "FizzBuzz";
        }
        else if(i%3 == 0) {
            ans += "Fizz";
        }
        else if(i%5 == 0) {
            ans += "Buzz";
        }
        else {
            ans += to_string(i);
        }

        v.push_back(ans);
    }

    return v;
}