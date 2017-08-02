class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        auto n = height.size();
        auto h = 0;
        for(auto _h : height){
            h = max(_h, h);
        }
        
        int sum = 0;
        
        for(int alt = h; alt >= 1; -- alt){
            
            int left_bound = 0;
            for(; left_bound < n; ++left_bound){
                if(alt <= height[left_bound]){
                    break;
                }
            }
            // left_bound
            
            if(left_bound == n){
                continue;
            }
            
            int right_bound = n - 1;
            for(; right_bound >= 0; --right_bound){
                if(alt <= height[right_bound]){
                    break;
                }
            }
            // right_bound
            
            if(left_bound == right_bound){
                continue;
            }

            
            sum += (right_bound - left_bound - 1);
            
            for(int i = left_bound + 1; i <= right_bound - 1; ++i){
                if(height[i] >= alt){
                    sum --;
                }
            }
        }
        
        return sum;
        
    }
};
