class Solution {
public:

    priority_queue<long long> left; // max heap
    priority_queue<long long, vector<long long>, greater<long long>> right; // min heap
    
    unordered_map<long long,int> delayed;

    int leftSize = 0;
    int rightSize = 0;


    void prune(priority_queue<long long>& heap){

        while(!heap.empty()){

            long long x = heap.top();

            if(delayed.count(x)){
                delayed[x]--;

                if(delayed[x]==0)
                    delayed.erase(x);

                heap.pop();
            }
            else
                break;
        }
    }


    void pruneRight(){

        while(!right.empty()){

            long long x = right.top();

            if(delayed.count(x)){

                delayed[x]--;

                if(delayed[x]==0)
                    delayed.erase(x);

                right.pop();
            }
            else
                break;
        }
    }


    void balance(){

        if(leftSize > rightSize + 1){

            right.push(left.top());
            left.pop();

            leftSize--;
            rightSize++;

            prune(left);
        }


        else if(leftSize < rightSize){

            left.push(right.top());
            right.pop();

            leftSize++;
            rightSize--;

            pruneRight();
        }
    }


    void add(long long num){

        if(left.empty() || num <= left.top()){

            left.push(num);
            leftSize++;

        }
        else{

            right.push(num);
            rightSize++;

        }

        balance();
    }


    void remove(long long num){

        delayed[num]++;


        if(num <= left.top())
            leftSize--;
        else
            rightSize--;


        prune(left);
        pruneRight();

        balance();
    }


    double getMedian(int k){

        prune(left);
        pruneRight();

        if(k%2)
            return left.top();

        return ((double)left.top() + right.top()) / 2.0;
    }


    vector<double> medianSlidingWindow(vector<int>& nums, int k) {


        vector<double> ans;


        for(int i=0;i<nums.size();i++){

            add(nums[i]);


            if(i>=k-1){

                ans.push_back(getMedian(k));


                remove(nums[i-k+1]);
            }
        }


        return ans;
    }
};