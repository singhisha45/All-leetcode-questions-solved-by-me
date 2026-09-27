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
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode *temp=head;
        ListNode *ptr=head;
        ListNode *ptr1 = head;

        while(temp!=NULL && temp -> next != NULL){
            ptr1 = ptr;
            ptr = ptr -> next;
            temp = temp -> next -> next;
        }
     
        ptr1 -> next = ptr1 -> next -> next;
        ptr -> next = nullptr;
        //hello
        return head;
    }
};
