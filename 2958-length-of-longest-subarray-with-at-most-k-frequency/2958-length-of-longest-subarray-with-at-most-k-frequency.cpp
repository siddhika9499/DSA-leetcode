class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int> freq;
        int count = 0;
        int left = 0;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq[nums[right]] > k){
                freq[nums[left]]--;
                left++;
            }
            count = max(count, right-left+1);
        }
        return count;
    }
};