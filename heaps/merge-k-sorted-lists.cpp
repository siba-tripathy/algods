


//AC
//https://leetcode.com/problems/merge-k-sorted-lists


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


 // By default we get a max heap in STP priority_queue, so to get min heap we need the a > b comparision
struct compare {
	bool operator()(ListNode* a, ListNode* b) {
		return a->val > b->val;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> non_empty_lists;
        for(ListNode* list : lists) {
            if (list!= NULL) {
                non_empty_lists.push_back(list);
            }
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq(non_empty_lists.begin(), non_empty_lists.end());
        ListNode* ans_end = NULL;
        ListNode* ans_head = NULL;
        while(!pq.empty()) {
        	ListNode* t = pq.top();
        	ListNode* n = new ListNode(t->val);
            if (ans_head == NULL) {
                ans_head = n;
                ans_end = n;
            } else {
                ans_end->next = n;
                ans_end=ans_end->next;
            }
            pq.pop();
            if(t->next != NULL) {
                pq.push(t->next);
            }
        }
        return ans_head;
    }
};