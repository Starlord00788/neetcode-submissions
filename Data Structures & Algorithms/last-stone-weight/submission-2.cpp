class Solution {
public:
    // first we will use brute force
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxH(stones.begin(),stones.end());
        while(maxH.size()>1){
            int y = maxH.top();
            maxH.pop();
            int x = maxH.top();
            maxH.pop();
            if(y!=x){
                maxH.push(y-x);
            }
        }

        return maxH.empty() ? 0 : maxH.top();

        
    }
};
