#include <string>
#include <vector>

using namespace std;

int minimumPushes(string word) {
    vector<int> counts(26, 0);

    for (int i = 0; i < word.size(); i++) {
        counts[word[i] - 'a']++;
    }

    sort(counts.rbegin(), counts.rend());

    int tracker = 0;
    int ans = 0;

    for (int i = 0; i < counts.size(); i++) {
        ans += counts[i] * ((tracker / 8) + 1);
        tracker++;
    }

    return ans;
}