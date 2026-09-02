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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        ListNode* newHead = NULL ;
        ListNode* tail = NULL;

        ListNode* temp = head ;
        while(temp != NULL){
             bool found = false;
            if(s.count(temp->val)==0){
                ListNode* newNode = new ListNode(temp->val);
                if(newHead == NULL){
                    newHead = newNode;
                    tail = newNode;
                }else {
                     tail->next = newNode;
                    tail = newNode;
                }
            }
            temp = temp -> next ;
        }



        return newHead ;
        }
    
};