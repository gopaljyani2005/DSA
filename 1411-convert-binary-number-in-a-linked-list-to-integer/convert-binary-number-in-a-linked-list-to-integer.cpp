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

int funct(ListNode* head){
    if(head==NULL){
        return 0;
    }
    else{
        return 1 + funct(head->next);
    }
} 


int DecValueFunct(ListNode* head, int p){
    if(head==NULL){
        return 0;
    }
    else{
        return head->val * pow(2,p) + DecValueFunct(head->next, p-1);
    }
}

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int len = funct(head);

        return DecValueFunct(head,len-1);
    }
};