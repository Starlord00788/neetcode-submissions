
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<vector<int>> dist;

        for(int i=0;i<n;i++){
            int distance = pow(points[i][0]-0,2) + pow(points[i][1]-0,2);
            dist.push_back({distance,i});
        }

        sort(dist.begin(),dist.end());

        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            vector<int> temp = points[dist[i][1]];
            result.push_back(temp);
        }
        return result;

    }
};
