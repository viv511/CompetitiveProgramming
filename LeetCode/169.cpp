//https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int curVal = nums[0];
    int maxCount = 1;
    int counter = 1;
    int ans = curVal;
    for(int i=1; i<nums.size(); i++) {
        if(nums[i] == curVal) {
            counter++;
        }
        else {
            if(counter > maxCount) {
                ans = curVal;
                maxCount = counter;
            }
            counter = 1;
            curVal = nums[i];
        }
    }

    if (counter > maxCount) {
        ans = curVal;
    }

    cout << ans << "\n";
}