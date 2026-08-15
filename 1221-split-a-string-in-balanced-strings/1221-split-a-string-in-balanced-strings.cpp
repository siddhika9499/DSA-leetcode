class Solution {
public:
    int balancedStringSplit(string s) {
        map<char,int> freq;
        int left = 0;
        int count = 0;
        for(int right = 0; right < s.size(); right++){
            freq[s[right]]++;
            if(freq['R'] == freq['L']){
                count++;
                while(left != right+1){
                    freq[s[left]]--;
                    left++;
                }
            }
        }
        return count;
    }
};