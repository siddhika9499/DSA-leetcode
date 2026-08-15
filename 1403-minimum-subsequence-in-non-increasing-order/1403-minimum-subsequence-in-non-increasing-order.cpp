class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int sum = 0;
        for(int i:nums){
            sum += i;
        }
        vector<int>ans;
        int nextsum = 0;
        for(int i=0; i<nums.size(); i++){
            nextsum += nums[i];
            sum -= nums[i];
            ans.push_back(nums[i]);
            if(nextsum > sum){
                break;
            }
        }
        return ans;
    }
};