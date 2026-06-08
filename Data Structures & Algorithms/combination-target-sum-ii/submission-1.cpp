class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates , target , 0);
        return result;
    }

    void backtrack(vector<int>& candidates, int target, int index){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(target<0 || index==candidates.size()) return;

        for(int i = index; i < candidates.size(); i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;

            temp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i+1);
            temp.pop_back();
        }
        
    }
};
