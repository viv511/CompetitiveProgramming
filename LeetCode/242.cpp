//https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool isAnagram(string s, string t) {
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    if(s == t) {
        return true;
    } else {
        return false;
    }
}