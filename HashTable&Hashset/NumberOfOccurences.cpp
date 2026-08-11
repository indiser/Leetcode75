#include<iostream>
#include<unordered_map>
#include<map>
#include<set>
#include<vector>
using namespace std;

class Solution
{
    public:
        bool uniqueOccurrrence(vector<int> &arr)
        {
            unordered_map<int,int> mp;
            set<int> st;

            for(int val:arr)
            {
                mp[val]++;
            }

            for(auto it=mp.begin();it!=mp.end();it++)
            {
                if(st.find(it->second) != st.end())
                {
                    return false;
                }
                st.insert(it->second);
            }
            return true;
        }
};

int main()
{
    // vector<int> arr={-3,0,1,-3,1,1,1,-3,10,0};
    vector<int> arr={1,2};

    Solution s;
    cout<<s.uniqueOccurrrence(arr)<<endl;
}