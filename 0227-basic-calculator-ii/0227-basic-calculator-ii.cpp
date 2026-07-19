class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long lastNum = 0;
        long long ans = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c))
                num = num * 10 + (c - '0');

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                if (sign == '+') {
                    ans += lastNum;
                    lastNum = num;
                }
                else if (sign == '-') {
                    ans += lastNum;
                    lastNum = -num;
                }
                else if (sign == '*') {
                    lastNum = lastNum * num;
                }
                else if (sign == '/') {
                    lastNum = lastNum / num;
                }

                sign = c;
                num = 0;
            }
        }

        return ans + lastNum;
    }
};