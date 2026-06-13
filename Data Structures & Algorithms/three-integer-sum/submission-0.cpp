class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        set<vector<int>> hashset;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-2;i++){
            int target = -nums[i];
            int left = i+1, right = nums.size()-1;
            while(right>left){
                if(nums[left]+nums[right]>target){
                    right--;
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }
                else{
                    hashset.insert({nums[i],nums[left++] , nums[right--]});
                }

            }
        }

        answer.assign(hashset.begin(),hashset.end());
        return answer;

    }
};
