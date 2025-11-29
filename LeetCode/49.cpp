//https://leetcode.com/problems/group-anagrams/

#include <vector>
#include <string>
#include <map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<string>> mp;

    for(auto str: strs) {
        string sortedStr = str;
        sort(sortedStr.begin(), sortedStr.end());

        mp[sortedStr].push_back(str);
    }

    vector<vector<string>> res;
    for(auto it: mp) {
        res.push_back(it.second);
    }

    return res;
}
