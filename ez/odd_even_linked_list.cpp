

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *odd_tail = head, *even_tail = head->next, *even_head = head->next;
        while (even_tail && even_tail->next)
        {
            odd_tail->next = even_tail->next;
            even_tail->next = even_tail->next->next;
            odd_tail = odd_tail->next;
            even_tail = even_tail->next;
        }
        odd_tail->next = even_head;
        return head;
    }
};