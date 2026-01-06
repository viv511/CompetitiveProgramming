//https://leetcode.com/problems/jewels-and-stones/description/

#include <string>
#include <set>
using namespace std;

int numJewelsInStones(string jewels, string stones) {
    set<char> s;
    for(auto a : jewels) {
        s.insert(a);
    }

    int c = 0;
    for(auto a : stones) {
        if(s.find(a) != s.end()) c++;
    }

    return c;
}