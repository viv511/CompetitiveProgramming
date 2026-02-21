#include <vector>
#include <string>
using namespace std;

vector<string> res = {};
vector<string> num = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void backtrack(int i, string cur, string digits) {
    if(i == digits.size()) {
        res.push_back(cur);
        return;
    }
    else {
        // 2 - 9 (so sub by 2 to index into)
        // for each c, add to cur and backtrack 1 more
        for (char c : num[digits[i] - '2']) {
            backtrack(i + 1, cur + c, digits);
        }
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) return {};

    // pass in empty string and size 0 to start
    backtrack(0, "", digits);
    
    return res;
}       
