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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* Alist = headA;
        ListNode* Blist = headB;
        int Alen = 0;
        int Blen = 0;
        while (headA != nullptr){
            Alen++;
            headA = headA -> next;
        }
        while (headB != nullptr){
            Blen++;
            headB = headB -> next;
        }
        headA = Alist;
        headB = Blist;
        int ABlen = (Alen > Blen) ? Alen - Blen : Blen - Alen;
        if (Alen > Blen){
            while(ABlen){
                headA = headA -> next;
                ABlen--;
            }
        }
        else {
            while(ABlen){
                headB = headB -> next;
                ABlen--;
            }
        }
        while ( (headA != nullptr) && (headB != nullptr) && (headA != headB) ){
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};