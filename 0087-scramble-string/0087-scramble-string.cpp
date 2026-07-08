class Solution {
public:

    unordered_map<string,bool> dp;

    bool solve(string s1, string s2){

        // Same strings are already scramble
        if(s1 == s2)
            return true;


        // Create key for memoization
        string key = s1 + "#" + s2;

        if(dp.find(key) != dp.end())
            return dp[key];


        // Character frequency check
        vector<int> freq(26,0);

        for(char c:s1)
            freq[c-'a']++;

        for(char c:s2)
            freq[c-'a']--;


        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                return dp[key]=false;
        }


        int n=s1.length();


        // Try every possible split
        for(int i=1;i<n;i++){

            // Case 1: No swap
            bool noSwap =
            solve(s1.substr(0,i), s2.substr(0,i))
            &&
            solve(s1.substr(i), s2.substr(i));


            // Case 2: Swap
            bool swap =
            solve(s1.substr(0,i), s2.substr(n-i))
            &&
            solve(s1.substr(i), s2.substr(0,n-i));


            if(noSwap || swap)
                return dp[key]=true;
        }


        return dp[key]=false;
    }



    bool isScramble(string s1, string s2) {

        if(s1.length()!=s2.length())
            return false;


        return solve(s1,s2);
    }
};