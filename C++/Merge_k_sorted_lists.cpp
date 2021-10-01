/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwo(ListNode *h1, ListNode *h2)
    {
        if (!h1)
            return h2;
        if (!h2)
            return h1;
        ListNode *head = (h1->val < h2->val) ? h1 : h2;
        head->next = (h1->val < h2->val) ? mergeTwo(h1->next, h2) : mergeTwo(h1, h2->next);
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return NULL;
        }
        while (lists.size() > 1)
        {
            lists.push_back(mergeTwo(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};