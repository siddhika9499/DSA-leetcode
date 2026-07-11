class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int maxWindow = 0;
        for(int i=0; i<k;i++){
            maxWindow += nums[i];
        }
        int maxSum = maxWindow;
        for(int i=k; i<n; i++){
            maxWindow += nums[i];
            maxWindow -= nums[i-k];
            maxSum = max(maxSum,maxWindow);
        }
        return (double)maxSum/k;
    }
};