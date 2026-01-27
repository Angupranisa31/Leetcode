class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0 , head);
        ListNode* last = dummy;
        while(true){
            ListNode* node = last;
            for(int i = 0; i < k && node; ++i) node = node->next;
            if(!node) break;
            ListNode* prev = node->next;
            ListNode* curr = last->next;
            for(int i = 0; i < k; ++i){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp = last->next;
            last->next = node;
            last = temp;
        }
        return dummy->next;
    }
};