#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<ctype.h>
#include<string>
using namespace std;

/*
Time Complexity: O(M) - where M is the length of the final decoded string
Space Complexity: O(M) - for storing the decoded result and stack operations
*/
class Solution
{
	public:
		string decodedString(string str)
		{
			stack<int> numStack;
			stack<string> st;
			string currString="";
			int num = 0;
			
			for(char c:str)
			{
				if(isdigit(c))
				{
					num = num * 10 + (c - '0'); //To take 3 digits instead of 1
				}
				else if(c=='[')
				{
					numStack.push(num);
					num = 0;
					st.push("");
				}
				else if(c==']')
				{
					int k = numStack.top(); numStack.pop();
					string strToRepeat = st.top(); st.pop();
					string temp = "";
					for (int i = 0; i < k; i++) temp += strToRepeat;
					
					if(!st.empty()) st.top() += temp;
					else currString += temp;
				}
				else
				{
					if(!st.empty()) st.top() += c;
					else currString += c;
				}
			}
			return currString;
		}
};

int main()
{
	string str="3[a2[c]]";
	Solution s;
	cout<<s.decodedString(str)<<endl;
}