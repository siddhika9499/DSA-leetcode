class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string sub = "";
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] == ' '){
                reverse(sub.begin(),sub.end());
                ans += sub;
                ans += ' ';
                sub = "";
            }else{
                sub += s[i];
            }
        }
        reverse(sub.begin(),sub.end());
        ans += sub;
        return ans;
    }
};