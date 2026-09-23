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
        ListNode* addTwoNumbers(ListNode* &head1, ListNode* &head2) {
            ListNode * temp1 = head1;
            ListNode * temp2 = head2;
            ListNode * dummy = new ListNode(-1);
            ListNode* dummy_temp = dummy;
            int carry = 0;
            int sum = 0;

            while(temp1 != NULL && temp2 != NULL)
            {
                sum = temp1 -> val + temp2 -> val + carry;
                carry = sum / 10;
                dummy_temp -> next = new ListNode(sum%10);
                dummy_temp = dummy_temp -> next;
                temp1 = temp1 -> next;
                temp2 = temp2 -> next;
            }
            while(temp1 != NULL)
            {
                sum = temp1 -> val + carry;
                carry = sum / 10;
                dummy_temp -> next = new ListNode(sum%10);
                dummy_temp = dummy_temp -> next;
                temp1 = temp1 -> next;
            }
            while(temp2 != NULL)
            {
                sum = temp2 -> val + carry;
                carry = sum / 10;
                dummy_temp -> next = new ListNode(sum%10);
                dummy_temp = dummy_temp -> next;
                temp2 = temp2 -> next;
            }
            if(carry != 0)
                dummy_temp -> next = new ListNode(carry);

            return dummy -> next;
        }
};