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
private:
    struct CompareNode {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq;
        for(ListNode* list: lists) {
            if (list)
                pq.push(list);
        } 
        ListNode* ans = new ListNode(0);
        ListNode* tail = ans;
        while (pq.size() > 0) {
            ListNode* min_node = pq.top();
            pq.pop();
            tail->next = min_node;
            tail = tail->next;
            if (min_node->next) pq.push(min_node->next);
        }
        return ans->next;
    }
};
