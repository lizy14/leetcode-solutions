class MedianFinder {
    
    vector<int> values;
    bool dirty = true;
    double median;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        auto it = lower_bound(values.begin(), values.end(), num);
        values.insert(it, num);
    }
    
    double findMedian() {
        int n = values.size();
        if(n % 2 == 1){
            median = values[n / 2];
        }else{
            auto a = values[n / 2 - 1];
            auto b = values[n / 2];
            median = a + (b - a) / 2.;
        }            
        return median;
    }
    

};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
