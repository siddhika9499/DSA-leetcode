class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int count = 0;
        string pure = "";
        for(char ch:s){
            if(ch != '-'){
                pure += toupper(ch);
            }
        }
        string ans = "";
        for(int i=pure.size()-1; i>=0; i--){
            ans += pure[i];
            count++;
            if(count == k && i!=0){
                ans += '-';
                count = 0;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};