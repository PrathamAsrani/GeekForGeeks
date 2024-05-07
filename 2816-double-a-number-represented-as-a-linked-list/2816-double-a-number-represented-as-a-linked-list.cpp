/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *reverseLL(ListNode *root){
        if(!root || !root->next)
            return root;
        ListNode *ptr = reverseLL(root->next);
        root->next->next = root;
        root->next = nullptr;
        return ptr;
    }
    ListNode* doubleIt(ListNode* head) {
        head = reverseLL(head);
        ListNode *ptr = head;
        int carry = 0;
        while(ptr){
            int num = ptr->val * 2;
            ptr->val = num%10 + carry;
            carry = num/10;
            ptr = ptr->next;
        }
        head = reverseLL(head);
        if(carry){
            ListNode *node = new ListNode(carry);
            node->next = head;
            return node;
        }
        return head;
    }
};

