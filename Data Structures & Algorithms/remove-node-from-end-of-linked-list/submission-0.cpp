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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr!=NULL){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Reverse list
        head = reverse(head);

        // Step 2: Remove nth node from start
        if(n == 1){
            ListNode* temp = head;
            head = head->next;
            delete temp;
        } else {
            ListNode* temp = head;
            for(int i = 1; i < n-1; i++){
                temp = temp->next;
            }
            ListNode* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        }

        // Step 3: Reverse again
        return reverse(head);
    }
};