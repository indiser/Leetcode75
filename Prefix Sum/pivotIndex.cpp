#include<iostream>
#include<vector>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            cout << "Pivot index is: " << i << endl;
            return 0;
        }
        leftSum += nums[i];
    }

    cout << "No pivot index found" << endl;
    return 0;
}