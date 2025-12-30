struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *n = new ListNode();
    ListNode *c = n;

    if(!l1) return l2;
    if(!l2) return l1;

    bool addOne = false;

    while(l1 || l2) {
        int sum = 0;

        if(l1) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2) {
            sum += l2->val;
            l2 = l2->next;
        }

        if(addOne) sum++;
        
        if(sum >= 10) {
            sum -= 10; addOne = true;
        }
        else {
            addOne = false;
        }

        n->val = sum;
                        
        if(l1 || l2) {
            n->next = new ListNode();
            n = n->next;
        }
    }

    if(addOne) {
        n->next = new ListNode(1);
    }

    return c;
}