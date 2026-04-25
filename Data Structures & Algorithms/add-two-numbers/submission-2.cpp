class Solution {
public:
    ListNode* addTwoNumbers(ListNode* num1, ListNode* num2) {
        ListNode* dummyHead = new ListNode(-1);
        ListNode* curr = dummyHead;
        ListNode* temp1 = num1;
        ListNode* temp2 = num2;

        int carry = 0;

        while(temp1 != NULL || temp2 != NULL || carry != 0) {
            int sum = carry;

            if(temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if(temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            curr->next = newNode;
            curr = curr->next;
        }

        return dummyHead->next;
    }
};