// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        int n = 0;
        auto tmp = head;
        while (tmp)
        {
            n++;
            tmp = tmp->next;
        }
        // move by n/2
        tmp = head;
        for (int i = 0; i < n / 2 - 1; i++)
        {
            tmp = tmp->next;
        }
        // delete tmp node
        auto next = tmp->next;
        tmp->next = tmp->next->next;
        delete next;
        return head;
    }
};