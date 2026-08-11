#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestAltitude(vector<int> &gain)
    {
    }
};

int main()
{
    vector<int> gain = {52,-91,72};
    int len = gain.size();
    int heighestPoint=0,curretAltitude=0;
    heighestPoint=curretAltitude;
    for(int val : gain)
    {
        curretAltitude += val;
        heighestPoint = max(heighestPoint,curretAltitude);
    }
    cout<<heighestPoint<<endl;
    
    return 0;
}