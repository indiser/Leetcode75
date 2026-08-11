#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val=x;
        next=NULL;
    }
};

//Time Complexity:O(n)
//Space Complexity:O(1)

class Solution
{
    public:
        void Traverse(ListNode*head)
        {
            while(head!=NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
        }
        ListNode *oddEvenLinkedList(ListNode *head)
        {
            if(!head || !head->next) return head;
            
            ListNode *odd_head=head;
            ListNode *even_head=head->next;
            ListNode *odd_tail=odd_head;
            ListNode *even_tail=even_head;

            while(even_tail != NULL && even_tail->next != NULL)
            {
                odd_tail->next=even_tail->next;
                odd_tail=odd_tail->next;
                even_tail->next=odd_tail->next;
                even_tail=even_tail->next;
            }
            odd_tail->next=even_head;
            return head;
        }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    head = s.oddEvenLinkedList(head);
    s.Traverse(head);
    cout << endl;
    return 0;
}