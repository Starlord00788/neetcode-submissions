class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // what if we apply a simple maxHeap in tihs
        priority_queue<int> maxHeap;
        vector<int> count(26,0);
        for(int i=0;i<tasks.size();i++){
            count[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(count[i]>0) maxHeap.push(count[i]);
        }

        int time = 0;
        queue<pair<int,int>> qt;

        while(!maxHeap.empty() || !qt.empty()){
            time++;
            if(!maxHeap.empty()){
                int front = maxHeap.top();
                maxHeap.pop();
                if(front-1>0){
                    qt.push({front-1,time+n});
                }
            }
            if(!qt.empty() && qt.front().second == time){
                maxHeap.push(qt.front().first);
                qt.pop();
            }
            
        }

        return time;
    }
};
