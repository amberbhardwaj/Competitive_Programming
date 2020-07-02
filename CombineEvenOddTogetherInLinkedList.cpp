/*

Given a singly linked list, group all odd nodes together followed by the even nodes. 
Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL

*/



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
    int getLength(ListNode* head)
    {
        int cnt = 0;
        while (head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }
    void print(ListNode* head)
    {
        while (head)
        {
            cout << head->val << "\t";
            head = head->next;
        }
        cout << "\n";
    }
    ListNode* oddEvenList(ListNode* head) {
        // If there is an empty list
        if (head == nullptr) return nullptr;
        
        {
            // When more than 2 elements are present 
            
            ListNode* odd = head;
            ListNode* even = head->next;
            // To hold the pointer of even list so that 
            // we can combine it with odd list at the end
            ListNode* temp = even; 
            
            // 1 2   [3]   4 5 nullptr
            // odd - 1,3,5
            // even- 2,4 
            while ((even != nullptr) && (even->next != nullptr))
            {
                //follow example 1 to understand better 
                odd->next = even->next;
                odd = odd->next;
                even->next = odd->next;
                even = even->next;
            }
            //Assigning even head at the end of odd list
            odd->next = temp;
            
            return head;
        }
        
        return nullptr;
    }
};
