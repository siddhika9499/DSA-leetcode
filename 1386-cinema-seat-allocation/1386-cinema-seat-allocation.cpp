class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats using a bitmask for each row
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            mp[row] |= (1 << col);
        }

        // Initially assume every row can fit 2 families
        int ans = 2 * n;

        for (auto &[row, mask] : mp) {
            
            // We assumed 2 families for this row.
            // Recalculate it based on reservations.
            int families = 0;

            // Seats 2,3,4,5
            bool left = !(mask & (1 << 2)) &&
                        !(mask & (1 << 3)) &&
                        !(mask & (1 << 4)) &&
                        !(mask & (1 << 5));

            // Seats 4,5,6,7
            bool middle = !(mask & (1 << 4)) &&
                          !(mask & (1 << 5)) &&
                          !(mask & (1 << 6)) &&
                          !(mask & (1 << 7));

            // Seats 6,7,8,9
            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            if (left && right) {
                families = 2;
            }
            else if (left || middle || right) {
                families = 1;
            }

            // We already counted 2 for this row
            ans -= 2;
            ans += families;
        }

        return ans;
    }
};