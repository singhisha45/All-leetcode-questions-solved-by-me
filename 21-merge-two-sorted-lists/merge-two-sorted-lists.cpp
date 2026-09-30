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
        if (arr.empty()) return nullptr;
        
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i = 1; i< arr.size(); i++){
            ListNode* a = new ListNode(arr[i]);
            temp -> next = a;
            temp = temp -> next;
        }
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;
        ListNode *temp1 = list1;
        ListNode *temp2 = list2;

        while(temp1 != NULL){
            arr.push_back(temp1 -> val);
            temp1 = temp1 -> next;
        }

        while(temp2 != NULL){
            arr.push_back(temp2 -> val);
            temp2 = temp2 -> next;
        }

        sort(arr.begin(), arr.end());
        return convert(arr);
    }
};