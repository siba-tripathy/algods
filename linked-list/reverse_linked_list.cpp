#include <bits/stdc++.h>
using namespace std;

//Easy. https:leetcode.com/problems/reverse-linked-list

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* revHead = NULL;

        while (head != NULL) {
            ListNode* remainingOriginalHead = head->next;

            head->next = revHead;

            revHead = head;

            head = remainingOriginalHead;
        }

        return revHead;
    }
};