class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int x=1; x<nums.size(); x++){
            if(nums[x] == nums[x-1] + 1){
                sum += nums[x];
            }else{
                break;
            }
        }
        int x = sum;
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.count(x)){
            x++;
        }
        return x;
    }
};