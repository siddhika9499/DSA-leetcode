class Solution {
public:
    int countGoodSubstrings(string s) {

        int n = s.length();
        int count = 0;

        unordered_map<char,int> mp;

        int left = 0;

        for(int right = 0; right < n; right++){

            // Add current character
            mp[s[right]]++;


            // Maintain window size = 3
            if(right - left + 1 > 3){

                mp[s[left]]--;

                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }

                left++;
            }


            // Check valid window
            if(right - left + 1 == 3){

                if(mp.size() == 3)
                    count++;
            }
        }

        return count;
    }
};