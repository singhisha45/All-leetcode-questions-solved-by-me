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
    
    ListNode* convert(vector<int> arr){
        if(arr.size() == 0) return NULL;
        ListNode *head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i=1; i< arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            
            temp -> next = newNode;
            temp = temp -> next;
        }
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        for (int i = 0; i < lists.size(); i++){
            ListNode *t2 = lists[i];
            while(t2 != NULL){
                arr.push_back(t2 ->val);
                t2 = t2 -> next;
            }
        }
        sort(arr.begin(), arr.end());
        return convert(arr);
    }
};