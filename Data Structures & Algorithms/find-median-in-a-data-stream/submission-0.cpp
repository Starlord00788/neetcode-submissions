class MedianFinder {

    priority_queue<int , vector<int> , greater<int>> minHeap;
    priority_queue<int> maxHeap;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(!minHeap.empty() && minHeap.top() < num){
            minHeap.push(num);
        }
        else{
            maxHeap.push(num);
        }

        if(maxHeap.size()>1+minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size()>1 + maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

    }
    
    double findMedian() {
        if(minHeap.size()==maxHeap.size()){
            return ((double)minHeap.top() + maxHeap.top())/2.0;
        }
        return (minHeap.size()>maxHeap.size() ? minHeap.top() : maxHeap.top());
    }
};
