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

    ListNode* reverse(ListNode* first, ListNode* last) {
        ListNode* prev = last;
        while (first != last) {
            ListNode* nxt = first->next;
            first->next = prev;
            prev = first;
            first = nxt;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {

            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth; i++)
                kth = kth->next;

            if (!kth)
                break;

            ListNode* groupNext = kth->next;
            ListNode* groupStart = groupPrev->next;

            groupPrev->next = reverse(groupStart, groupNext);

            groupPrev = groupStart;
        }

        return dummy.next;
    }
};