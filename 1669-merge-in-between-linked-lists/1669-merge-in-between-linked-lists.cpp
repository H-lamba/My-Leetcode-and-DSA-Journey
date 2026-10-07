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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * pt1 = list1;
        int node = 0;
        while(node!=a-1)
        {
            pt1 = pt1->next;
            node++;
        }
        ListNode * pt2 = pt1;
        while(node!=b+1)
        {
            pt2= pt2->next;
            node++;
        }
        pt1->next = list2;
        while(list2->next != nullptr)
        {
            list2 = list2->next;
        }
        list2->next = pt2;
        return list1;
    }
};