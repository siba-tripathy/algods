#include<bits/stdc++.h>
using namespace std;

// Easy-Med Trick. Remember. https://leetcode.com/problems/linked-list-cycle/

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
   public:
    bool hasCycle(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL) {
                fast = fast->next;
            }
            if (slow == fast && slow != NULL) {
                return true;
            }
        }
        return false;
    }
};