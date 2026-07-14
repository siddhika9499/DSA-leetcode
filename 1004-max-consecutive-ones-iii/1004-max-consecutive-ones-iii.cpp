class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int left = 0;
        int ans = 0;
        for(int right=0; right<nums.size(); right++){
            freq[nums[right]]++;
            while(freq[0] > k){
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};