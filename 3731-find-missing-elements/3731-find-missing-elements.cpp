class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> result;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]+1){
                int p = nums[i-1]+1;
                while( p != nums[i]){
                    result.push_back(p);
                    p++;
                }
            }
        }
        return result;
    }
};