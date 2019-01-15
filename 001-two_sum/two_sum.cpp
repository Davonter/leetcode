#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> record;
        for(int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if(record.find(complement) != record.end())
            {
                int res[] = {record[complement], i};
                return vector<int>(res, res+2);
            }
            
            record[nums[i]] = i;
        }
        
        throw invalid_argument("The input has no solution");
    }
};

int main(void)
{
    int nums[4] = {2, 3, 4, 1};
    
    vector<int> nums_vec(nums, nums + sizeof(nums)/sizeof(int));
    
    int target = 7;
    
    vector<int> vec = Solution().twoSum(nums_vec, target);
    
    for(int e:vec)
        cout << e << " ";
    cout << endl;
    
    return 0;
}