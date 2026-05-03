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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr){
            return head;
        }
        if(head->val==val && head->next==nullptr){
            return nullptr;
        }
        ListNode* temp1=new ListNode(0);
        temp1->next=head;
        ListNode* temp=temp1;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->next->val==val){
                ListNode* up=temp->next;
                temp->next=temp->next->next;
                //up->next=nullptr;
                delete up;
            }
            else{
                temp=temp->next;
                //up=up->next;
            }
        }
        return temp1->next;
    }
};