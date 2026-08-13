#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    private:
        unsigned int k;
        priority_queue<int, vector<int>, greater<int>> pq;

    public:
        KthLargest(int k, vector<int>& nums) {
            this->k = k;

            for (auto a : nums) {
                add(a);
            }
        }
        
        // @assert(maintains size of pq as <= k)
        int add(int val) {
            if (pq.size() < k) {
                pq.push(val);
            }
            else if (val > pq.top()) {
                pq.pop();
                pq.push(val);
            }
            
            return pq.top();
        }
};