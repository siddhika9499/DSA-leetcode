class Solution {
public:
    unordered_set<int>st;
    void solve(vector<int> &digits, vector<bool> &vis , int num, int len){
        if(len == 3){
            if(num % 2 == 0){
                st.insert(num);
            }
            return;
        }
        for(int i=0; i<digits.size();i++){
            if(vis[i]) continue;
            if(len == 0 && digits[i] == 0) continue;
            vis[i] = true;
            solve(digits,vis,num*10+digits[i],len+1);
            vis[i] = false;
        }
    }
    int totalNumbers(vector<int>& digits) {
        vector<bool>vis(digits.size() , false);
        solve(digits,vis,0,0);
        return st.size();
    }
};