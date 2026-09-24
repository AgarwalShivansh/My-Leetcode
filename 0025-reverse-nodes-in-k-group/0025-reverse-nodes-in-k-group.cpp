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

    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* temp = head;
        ListNode* curr = temp;
        ListNode* prev = NULL;

        while (temp != NULL)
        {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* getKthNode(ListNode* temp, int k)
    {
        k = k - 1;

        while (temp != NULL && k > 0)
        {
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* temp = head;
        ListNode* prevLast = NULL;

        while (temp != NULL)
        {
            // Find kth node of current group
            ListNode* kThNode = getKthNode(temp, k);

            // Less than k nodes remaining
            if (kThNode == NULL)
            {
                if (prevLast)
                    prevLast->next = temp;

                break;
            }

            // Save the next group
            ListNode* nextNode = kThNode->next;

            // Disconnect current group
            kThNode->next = NULL;

            // Reverse current group
            reverseLinkedList(temp);

            // Connect reversed group with previous groups
            if (temp == head)
            {
                head = kThNode;
            }
            else
            {
                prevLast->next = kThNode;
            }

            // temp is now the last node of reversed group
            prevLast = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};