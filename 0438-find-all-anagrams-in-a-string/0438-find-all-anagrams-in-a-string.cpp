class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int>ans;
        vector<int>pCount(26,0);
        vector<int>windowCount(26,0);
        if(n<m) return ans;
        for(char ch: p){
            pCount[ch - 'a']++;
        }
        int left = 0;
        for(int right=0; right<n; right++){
            windowCount[s[right] - 'a']++;
            if(right-left+1 > m){
                windowCount[s[left] - 'a']--;
                left++;
            }
            if(right-left+1 == m){
                if(windowCount == pCount){
                    ans.push_back(left);
                }
            }
        }
        return ans;
    }
};