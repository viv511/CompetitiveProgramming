#include <string>
using namespace std;

string strip(string s) {
    string res = "";

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            res += c;
        }
        else if (c >= 'A' && c <= 'Z') {
            res += (c - 'A' + 'a');
        }
        else if (c >= '0' && c <= '9') {
            res += c;
        }
    }

    return res;
}

bool isPalindrome(string s) {
    string pali = strip(s);

    for (size_t i = 0; i < pali.size(); i++) {
        if (pali[i] != pali[pali.size() - 1 - i]) {
            return false;
        }
    }

    return true;
}