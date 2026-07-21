class Solution {
    public int maxActiveSectionsAfterTrade(String s) {

        int n = s.length();
        int ones = 0;
        for (char c : s.toCharArray()) {
            if (c == '1') ones++;
        }

        String t = "1" + s + "1";
        int m = t.length();

        int ans = ones;

        int i = 1;
        while (i < m - 1) {

            if (t.charAt(i) == '0') {

                int leftZero = 0;
                while (i < m && t.charAt(i) == '0') {
                    leftZero++;
                    i++;
                }

                int oneStart = i;
                int oneLen = 0;
                while (i < m && t.charAt(i) == '1') {
                    oneLen++;
                    i++;
                }

                int rightZero = 0;
                int j = i;
                while (j < m && t.charAt(j) == '0') {
                    rightZero++;
                    j++;
                }

                if (oneLen > 0 && leftZero > 0 && rightZero > 0) {
                    ans = Math.max(ans, ones + leftZero + rightZero);
                }

            } else {
                i++;
            }
        }

        return ans;
    }
}