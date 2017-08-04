class MaxHeap : priority_queue<int>{
    public:
        inline int Top(){
            return top();
        }
        inline void Push(int num){
            push(num);
        }
        inline void Pop(){
            pop();
        }
        inline int Size(){
            return size();
        }
};

class MinHeap : priority_queue<int>{
    public:
        inline int Top(){
            return - top();
        }
        inline void Push(int num){
            push(- num);
        }
        inline void Pop(){
            pop();
        }
        inline int Size(){
            return size();
        }
        
};

class MedianFinder {
    MaxHeap small;
    MinHeap large;
public:
    
    void addNum(int num) {
        small.Push(num);
        large.Push(small.Top());
        small.Pop();
        if(large.Size() > small.Size()){
            small.Push(large.Top());
            large.Pop();
        }
    }
    
    double findMedian() {
        if(large.Size() == small.Size()){
            return (small.Top() + large.Top()) / 2.;
        }else{
            return small.Top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
