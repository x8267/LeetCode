/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if  (head == NULL)
            return NULL;
        if (head -> next == NULL)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; ++i){
            fast = fast -> next;
        }
        if (fast == NULL){
            return head -> next;
        }
        while (fast -> next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* temp = slow -> next;
        slow -> next = temp -> next;
        delete temp;
        return head;
    }
};