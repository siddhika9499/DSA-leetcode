class Solution {
public:
    bool checkRecord(string s) {
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(i>=2){
                if(s[i]=='L' && s[i-1]=='L' && s[i-2]=='L') return false;
            }
            if(s[i] == 'A'){
                count++;
                if(count >= 2) return false;
            }
        }
        return true;
    }
};