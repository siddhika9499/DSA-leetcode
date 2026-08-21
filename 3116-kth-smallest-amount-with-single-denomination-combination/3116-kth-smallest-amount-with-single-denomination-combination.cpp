class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();

        // lcm of two numbers
        auto lcm = [](long long a, long long b) {
            return a / std::gcd(a, b) * b;
        };

        // Count how many valid amounts <= x
        auto count = [&](long long x) {
            long long cnt = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long L = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        L = lcm(L, coins[i]);

                        if (L > x) {
                            valid = false;
                            break;
                        }
                    }
                }

                if (!valid) continue;

                long long ways = x / L;

                if (bits % 2 == 1)
                    cnt += ways;
                else
                    cnt -= ways;
            }

            return cnt;
        };

        long long low = 1;
        long long high = 1LL * (*max_element(coins.begin(), coins.end())) * k;

        while (low < high) {
            long long mid = low + (high - low) / 2;

            if (count(mid) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};