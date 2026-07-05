#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();

    unordered_set<int> s;
    s.reserve(nums.size());
    s.insert(nums.begin(), nums.end());

    // a sequence must have a beginning, so skip any that are not
    // keep track of longest length
    int ans = 0;
    for(int n : s) {
        if(!s.count(n - 1)) {
            int curr = n;

            while(s.count(curr + 1)) {
                curr++;
            }

            ans = max(ans, curr - n + 1);
        }
    }

    return ans;    
}

// #include <vector>
/* the follow is o(n log n) since im building the bst, problem asks for o(n)

struct node {
    int value;
    node *l;
    node *r;

    node(int v) : value(v), l(nullptr), r(nullptr) {}
};

// we dont add duplicate elements
node *insertNode(node *root, int v) {
    if(root == nullptr) return new node(v);

    // assert(tree has a root)
    int rootV = root->value;
    if(v < rootV) {
        root->l = insertNode(root->l, v);
    }
    else if (v > rootV) {
        root->r = insertNode(root->r, v);
    }

    // we return the same tree on duplicate value already existing
    return root;
}

void inorder(node *root, vector<int>& sorted) {
    if(root == nullptr) return;

    inorder(root->l, sorted);
    sorted.push_back(root->value);
    inorder(root->r, sorted);
}


int longestConsecutive(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();

    node *root = nullptr;

    for(int i = 0; i < nums.size(); i++) {
        root = insertNode(root, nums[i]);
    }

    vector<int> sortedNums;
    inorder(root, sortedNums);

    // assert(nums.size >= 2)

    int bestCount = -1;
    int counter = 1;
    for(int i=1; i<sortedNums.size(); i++) {
        if(sortedNums[i] == sortedNums[i-1] + 1) {
            counter++;
        }
        else {
            bestCount = max(counter, bestCount);
            counter = 1;
        }
    }
    // in case the last one in the vector increases count and its > max so far
    bestCount = max(counter, bestCount);

    return bestCount;
}
*/