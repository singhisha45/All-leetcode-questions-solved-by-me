/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//hi
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;

        map<ListNode*,int> mpp;
        ListNode *temp = headA;
        while(temp !=NULL){
            mpp[temp] = 1;
            temp = temp -> next;
        }
        //hereis
        temp = headB;
        while(temp !=NULL){
            if(mpp.find(temp) != mpp.end()){
                return temp;
            }
            temp = temp -> next;
        }
        return NULL;
    }
};
