#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class RecentCalls
{
    public:
        queue<int> qc;
        RecentCalls()
        {
            
        }
        int ping(int t)
        {
            qc.push(t);
            while(qc.front() < t-3000)
            {
                qc.pop();
            }
            return qc.size();
        }
};

int main()
{
    RecentCalls rc;
    cout << rc.ping(1) << endl;
    cout << rc.ping(100) << endl;
    cout << rc.ping(3001) << endl;
    cout << rc.ping(3002) << endl;
    return 0;
}

// Time Complexity: O(1) amortized per ping call
// Space Complexity: O(W) where W is the size of the time window (3000ms)