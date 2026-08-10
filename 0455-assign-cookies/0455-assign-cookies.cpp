class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gp = 0;
        int sp = 0;
        while(gp < g.size() && sp<s.size()){
            if(g[gp] <= s[sp]){
                gp++;
                sp++;
            }else{
                sp++;
            }
        }
        return gp;
    }
};