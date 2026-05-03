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
       // ListNode* temp=headA;
       ListNode* temp1;
        while(headA!=nullptr){
            temp1=headB;
            while(temp1!=nullptr){
                if(headA==temp1){
                    return headA;
                }
             temp1=temp1->next;   
            }
        headA=headA->next;
    }
    return nullptr;
    }
};