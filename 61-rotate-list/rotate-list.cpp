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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        int n=1;
        ListNode* number=head;
         while(number!=nullptr && number->next!=NULL){
                number=number->next;
                n++;
            }
        if(k>n){
        k=k%n;
        }
        for(int i=0;i<k;i++){
            ListNode* temp1=head;
            ListNode* temp2=head->next;
            while(temp2!=nullptr && temp2->next!=NULL){
                temp1=temp2;
                temp2=temp2->next;
            }
            if(temp2->next==nullptr){
            temp2->next=head;
            }
            temp1->next=nullptr;
            head=temp2;
        }
        return head;
    }
};