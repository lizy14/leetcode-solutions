/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        std::sort(
            intervals.begin(), 
            intervals.end(), 
            [](Interval a, Interval b){
                return a.start < b.start;
            }
        );
        
        vector<Interval> result;
        if(intervals.empty()){
            return result;
        }
        result.push_back(intervals.front());
        
        for(auto current : intervals){
            auto& last = result.back();
            if(current.start > last.end){
                result.push_back(current);
            }else{
                last.end = max(last.end, current.end);
            }
        }
        
        return result;
    }
};
