class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>pq;
        for(auto &row : matrix){
            for(int num: row){
                pq.push(num);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};