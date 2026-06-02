typedef pair<int , int> ppi;
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<ppi> maxHeap;

        for(int i=0;i<n;i++){
            int distance = pow(points[i][0],2) + pow(points[i][1],2);
            maxHeap.push({distance,i});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while(!maxHeap.empty()){
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return result;


    }
};
