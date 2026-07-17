class Solution {
public:
    string convertToBase7(int num) {
        string ans = "";
        if(num == 0) return "0";
        bool negative = false;
        if(num < 0){
            negative = true;
            num = -num;
        }
        while(num > 0){
            ans += to_string(num%7);
            num = num/7;
        }
        reverse(ans.begin(),ans.end());
        if(negative) ans = "-"+ans;
        return ans;
    }
};