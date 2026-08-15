class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> freq;

        for (char ch : tasks) {
            freq[ch]++;
        }

        int maxFreq = 0;

        for (auto p : freq) {
            maxFreq = max(maxFreq, p.second);
        }

        int countMax = 0;

        for (auto p : freq) {
            if (p.second == maxFreq) {
                countMax++;
            }
        }

        int ans = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), ans);
    }
};