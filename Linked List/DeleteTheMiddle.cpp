#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        void Traverse(ListNode *head)
        {
            while(head != NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
        }
        // Time Complexity: O(n) - traverse half the list once
        // Space Complexity: O(1) - only use constant extra space
        ListNode *deleteFromMiddle(ListNode *head)
        {
            if(!head || !head->next) return nullptr;
            
            ListNode *slow=head;
            ListNode *fast=head;
            ListNode *prev=nullptr;

            while(fast && fast->next)
            {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
            prev->next=slow->next;
            return head;
        }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(7);
    head->next->next->next->next = new ListNode(1);
    head->next->next->next->next->next = new ListNode(2);
    head->next->next->next->next->next->next = new ListNode(6);
    
    Solution s;
    // sol.Traverse(head);
    s.deleteFromMiddle(head);
    s.Traverse(head);
    return 0;
}
