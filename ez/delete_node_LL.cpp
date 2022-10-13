// https://leetcode.com/problems/delete-node-in-a-linked-list/discuss/65455/1-3-lines-C%2B%2BJavaPythonCCJavaScriptRuby
//  https://leetcode.com/problems/delete-node-in-a-linked-list/
// the beauty of pointer, and comparison with other languages
class Solution
{
public:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr) {}
    };
    // assumption: not the last node
    void deleteNode(ListNode *node)
    {
        ListNode *pre_node = nullptr;
        while (node->next)
        {
            node->val = node->next->val;
            pre_node = node;
            node = node->next;
        }
        // delete last node
        pre_node->next = nullptr;
    }

    // assumption: not the last node
    void deleteNode(ListNode *node)
    {
        auto tmp = node->next;
        *node = *(node->next);
        delete tmp;
    }

    // assumption: not the last node
    void deleteNode(ListNode *node)
    {
        auto tmp = node->next;
        node->val = tmp->val;
        node->next = tmp->next;
        delete tmp;
    }
};