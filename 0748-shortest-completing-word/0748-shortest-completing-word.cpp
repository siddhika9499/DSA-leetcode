class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {

        vector<int> need(26, 0);

        // Count required letters from licensePlate
        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                need[ch - 'a']++;
            }
        }

        string ans = "";

        for (string word : words) {

            vector<int> freq(26, 0);

            // Count letters in current word
            for (char ch : word) {
                freq[ch - 'a']++;
            }

            bool ok = true;

            // Check if word satisfies required frequencies
            for (int i = 0; i < 26; i++) {
                if (freq[i] < need[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                if (ans == "" || word.length() < ans.length()) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};