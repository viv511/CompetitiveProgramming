#include <vector>
#include <queue>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for(auto a : nums) {
        pq.push(a);
    }

    for(int i=0; i<k-1; i++) {
        pq.pop();
    }

    return pq.top();
}