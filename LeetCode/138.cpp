#include <unordered_map>

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

Node* copyRandomList(Node* head) {
    // two passes approach ~ O(n)

    // edge case
    if (!head) return nullptr;

    std::unordered_map<Node*, Node*> map;

    Node *curr = head;
    while (curr) {
        // first pass makes a hashmap from old -> new
        map[curr] = new Node(curr->val);

        curr = curr->next;
    }

    curr = head;
    while (curr) {
        // map[curr] gives us the new node assoc. w/ curr
        Node *newCurr = map[curr];

        // on second pass we must link its next + rand ptrs
        newCurr->next = map[curr->next];
        newCurr->random = map[curr->random];

        curr = curr->next;
    }

    return map[head];
}