#include <iostream>
using namespace std;
#include <vector>

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> output;
    for (int i = 0; i <= nums.size(); i++)
    {
        for (int j = i + 1; j <= nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                output.push_back(i);
                output.push_back(j);
            }
        }
    }
    return output;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums;
    for (int j = 0; j < n; j++)
    {
        int value;
        cin >> value;
        nums.push_back(value);
    }

    int target;
    cin >> target;

    vector<int> output;
    output = twoSum(nums, target);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }

    return 0;
}