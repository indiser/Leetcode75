#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution
{
    public:
        vector<int> asteroidCollison(vector<int> &asteroid)
        {
            stack<int> st;
            for(int i=0;i<asteroid.size();i++)
            {
                if(asteroid[i]>0)
                {
                    st.push(asteroid[i]);
                }
                else
                {
                    while(!st.empty() && st.top()>0 && st.top()<-asteroid[i])
                    {
                        st.pop();
                    }
                    if(st.empty() || st.top()<0)
                    {
                        st.push(asteroid[i]);
                    }
                    else if(st.top()==-asteroid[i])
                    {
                        st.pop();
                    }
                }
            }
            vector<int> ans(st.size());
            for(int i=st.size()-1;i>=0;i--)
            {
                ans[i]=st.top();
                st.pop();
            }
            return ans;
        }
};

int main()
{
    vector<int> asteroid={5,10,-5};
    vector<int> ans;

    Solution s;
    ans=s.asteroidCollison(asteroid);
    for(int val:ans)
    {
        cout<<val<<endl;
    }
    return 0;
}