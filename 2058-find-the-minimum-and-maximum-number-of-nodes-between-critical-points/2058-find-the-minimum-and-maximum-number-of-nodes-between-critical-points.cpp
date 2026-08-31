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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode * prev = head;
        head = head->next;
        vector<int> index;
        int size = 1;
        while(head->next && head->next->next)
        {
            if(head->val>prev->val && head->val>head->next->val)
            {
                index.push_back(size);
            }
            else if(head->val<prev->val && head->next->val>head->val)
            {
                index.push_back(size);
            }
            size++;
            head = head->next;
            prev = prev->next;
        }
        if(head->next && head->val>prev->val && head->val>head->next->val)
            {
                index.push_back(size);
            }
            else if(head->next && head->val<prev->val && head->next->val>head->val)
            {
                index.push_back(size);
            }
        if(index.size()<2) return {-1, -1};
        int maxi = index.back()-index[0];
        int mini = maxi;
        for(int i = 1; i<index.size(); i++)
        mini = min(mini, index[i]-index[i-1]);
        return {mini, maxi};
    }
};