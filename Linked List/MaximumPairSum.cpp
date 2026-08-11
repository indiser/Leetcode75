#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//Time Complexity:O(n)
//Space Complexity:O(n)

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x)
    {
        val=x;
        next=nullptr;
    }
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
        int pairSum(ListNode *head)
        {
            if(!head || !head->next) return 0;

            int maxSum=0,sum=0;
            vector<int> list;

            while(head != NULL)
            {
                list.push_back(head->val);
                head = head->next;
            }
            int start=0, end=list.size()-1;
            while(start <= end)
            {
                sum = list[start] + list[end];
                maxSum = max(maxSum, sum);
                start++;
                end--;
            }
            return maxSum;
        }
};

int main()
{
    ListNode* head = new ListNode(5);
    head->next = new ListNode(4);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    Solution s;
    cout<<s.pairSum(head)<<endl;
    return 0;
}