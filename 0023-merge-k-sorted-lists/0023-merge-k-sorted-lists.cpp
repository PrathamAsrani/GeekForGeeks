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
    ListNode *merge(ListNode *list1, ListNode *list2) {
      ListNode *start = nullptr, *ptr = nullptr;
      while (list1 && list2) {
        if (list1->val < list2->val) {
          if (!ptr) {
            ptr = list1;
            if (!start)
              start = ptr;
          } else {
            ptr->next = list1;
            ptr = ptr->next;
          }
          list1 = list1->next;
        } else {
          if (!ptr) {
            ptr = list2;
            if (!start)
              start = ptr;
          } else {
            ptr->next = list2;
            ptr = ptr->next;
          }
          list2 = list2->next;
        }
      }
      ListNode *remaining = (list1) ? list1 : list2;
      while(remaining){
          if (!ptr) {
            ptr = remaining;
            if (!start)
              start = ptr;
          } else {
            ptr->next = remaining;
            ptr = ptr->next;
          }
          remaining = remaining->next;
      }
      return start;
    }
    ListNode* mergeKLists(vector<ListNode*>& listArray) {
        int n = listArray.size();
        if(n == 0)
            return nullptr;
        if(n==1)
            return listArray[0];
        ListNode *start = listArray[0];
        for(int i = 1; i < n; i++){
            ListNode *a = listArray[i];
            start = merge(a, start);
        }
        return start;
    }
};