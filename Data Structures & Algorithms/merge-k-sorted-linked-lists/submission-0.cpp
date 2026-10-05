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
            pq.push(list);
        }
        ListNode* ans = nullptr;
        if (pq.size() > 0) ans = pq.top();
        while (pq.size() > 0) {
            ListNode* min_node = pq.top();
            pq.pop();
            if (min_node->next) pq.push(min_node->next);
            if (pq.size() > 0)
                min_node->next = pq.top();
            else min_node->next = nullptr;
        }
        return ans;
    }
};
