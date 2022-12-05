/**
 * Definition for singly-linked list.
 *
 */
// https://leetcode.com/problems/middle-of-the-linked-list/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != nullptr)
                fast = fast->next;
        }
        return slow;
    }
};