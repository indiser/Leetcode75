// Date: 11/08/2026
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

// Time Complexity: O(logk)
// Space Complexity: O(k)
class SmallestInfiniteSet
{
    public:
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_set<int> present;
        int cur;
        SmallestInfiniteSet()
        {
            cur = 1;
        }
        int popSmallest()
        {
            int result;
            if(!pq.empty())
            {
                result = pq.top();
                pq.pop();
                present.erase(result);
            }
            else
            {
                result = cur;
                cur++;
            }
            return result;
        }
        void addBack(int num)
        {
            if(num < cur && !present.count(num))
            {
                pq.push(num);
                present.insert(num);
            }
        }
};

int main()
{
    SmallestInfiniteSet *sis = new SmallestInfiniteSet();
    for (int i = 1; i <= 10; i++)
    {
        sis->addBack(i);
    }

    cout<< sis->popSmallest() <<endl;
    cout<< sis->popSmallest() <<endl;
    cout<< sis->popSmallest() <<endl;
    cout<< sis->popSmallest() <<endl;
    cout<< sis->popSmallest() <<endl;
    cout<< sis->popSmallest() <<endl;

    
    return 0;
}