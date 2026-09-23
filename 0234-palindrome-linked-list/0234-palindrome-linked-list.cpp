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
ListNode* reverse(ListNode* head)
{
    ListNode * prev = NULL;
    ListNode * curr = head;
    ListNode* temp = head;
    while(temp != NULL)
    {
        temp = temp -> next;
        curr -> next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* middle(ListNode* head)
{
    ListNode* slow = head;
    ListNode* fast = head -> next;
    while(fast != NULL && fast -> next != NULL)
    {
        slow = slow -> next;
        fast = fast  -> next -> next;
    }
    return reverse(slow -> next);
}

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* newHead = middle(head);
        ListNode* second = newHead;
        ListNode * temp = head;
        while(second != NULL)
        {
            if(temp->val != second ->val )
            return 0;
            second = second -> next;
            temp = temp -> next;
        }
        return 1;
    }
};