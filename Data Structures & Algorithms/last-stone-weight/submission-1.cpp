class Solution {
public:
    // first we will use brute force
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            int i=stones.size()-1;
            sort(stones.begin(),stones.end());
            int x = stones[i];
            int y = stones[i-1];
            if(x==y && stones.size()==2){
                return 0;
            }
            stones.pop_back();
            stones.pop_back();
            if(x!=y){
                stones.push_back(x-y);
            }
        }
        return stones[0];
        
    }
};
