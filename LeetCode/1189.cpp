#include <vector>
#include <string>
using namespace std;

int maxNumberOfBalloons(string text) {
    size_t n = text.length();
    int ans = (int)n + 1;

    // since only lowercase english letters
    // ascii range is 97 (a) to 122 (z), inclusive
    // subtract by 97 to achieve an indexing from char -> length 26 array
    // this can be used as a frequency table

    vector<int> freq(26, 0);
    for(int i=0; i<n; i++) {
        freq[((int)text[i])-97]++;
    }

    // after parsing, find the min count amongst all required words = answer
    // note: balloon has two l's and two o's, so must divide by two for those
    
    // ascii letters needed:
    // b = 98 (index 1)
    // a = 97 (index 0)
    // l = 108 (index 11) - COUNT TWICE
    // o = 111 (index 14) - COUNT TWICE
    // n = 110 (index 13)

    ans = min(ans, freq[1]);
    ans = min(ans, freq[0]);
    ans = min(ans, (int)(freq[11]/2));
    ans = min(ans, (int)(freq[14]/2));
    ans = min(ans, freq[13]);

    return ans;
}