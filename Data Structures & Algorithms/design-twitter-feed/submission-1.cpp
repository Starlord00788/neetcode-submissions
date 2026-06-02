typedef pair<int,int> ppi;
class Twitter {
    int tm = 0;
    unordered_map<int, unordered_set<int>> hashset;
    unordered_map<int, vector<ppi>> hashmap;
    
public:
    Twitter() {
        tm = 0 ;
    }
    
    void postTweet(int userId, int tweetId) {
        tm++;
        hashmap[userId].push_back({tm,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<ppi , vector<ppi> , greater<ppi>> minHeap;
        vector<ppi> temp = hashmap[userId];
        for(int i=0;i<temp.size();i++){
            minHeap.push(temp[i]);
            if(minHeap.size()>10) minHeap.pop();
        }

        for(int i : hashset[userId]){
            for(auto j : hashmap[i]){
                minHeap.push({j.first , j.second});
                if(minHeap.size()>10) minHeap.pop();
            }
        }

        vector<int> result;
        while(!minHeap.empty()) {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
    
    void follow(int followerId, int followeeId) {

        if(followerId == followeeId) return;
        hashset[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        hashset[followerId].erase(followeeId);

    }
};
