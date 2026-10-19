class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> result; 

       for (int i = 0; i < nums.size(); i++) {
            result[nums[i]] = i;
       }

       for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if(result.count(diff) && result[diff] != i) {
                return {i, result[diff]};
            }
       }

       return {};
    }
};
