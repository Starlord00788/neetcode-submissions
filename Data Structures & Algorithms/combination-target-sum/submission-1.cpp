class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result , temp, target , 0  , nums);
        return result;
    }

    void backtrack(vector<vector<int>>& result , vector<int> temp, int target , int index , vector<int>& nums){
        if(target==0){
            result.push_back(temp);
            return;
        }
        if(index>=nums.size() || target<0) return;

        temp.push_back(nums[index]);
        backtrack(result,temp , target-nums[index],index,nums);

        temp.pop_back();

        backtrack(result ,temp , target , index+1 , nums);
    }
};
