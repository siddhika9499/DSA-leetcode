class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int score = 0;
        int left = 0;
        int ans =0;
        unordered_map<int,int>freq;
        for(int right=0; right<n;right++){
            freq[nums[right]]++;
            ans += nums[right];
            while(freq[nums[right]] > 1){
                freq[nums[left]]--;
                ans -= nums[left];
                left++;
            }
            score = max(score, ans);
        }
        return score;
    }
};