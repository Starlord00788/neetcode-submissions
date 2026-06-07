class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(result , 0 , temp , nums );
        return result;
    }

    void backtrack(vector<vector<int>>& result, int index , vector<int> temp,vector<int>& nums){
        if(index==nums.size()){
            result.push_back(temp);
            return;
        }

        //take
        temp.push_back(nums[index]);
        backtrack(result,index+1,temp,nums);
        temp.pop_back();

        //not take
        backtrack(result,index+1,temp,nums);

    
    }
};
