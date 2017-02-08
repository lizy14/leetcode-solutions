class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        
        int i;
        int n = nums.size();
        vector<vector<int> > result;
        i = 0;
        while(i < n){
            int a = nums[i];
            
            vector<int> local_nums;
            for(auto it=nums.begin() + i + 1; it!=nums.end(); it++){
                local_nums.push_back(*it);
            }
            
            auto local_result = threeSum(local_nums, target - a);
            for(auto& _ : local_result){
                _.push_back(a);
                result.push_back(_);
            }
            
            while(i<n && nums[i]==a){
                i++;
            }
        }
        return result;
    }
    
    vector<vector<int> > threeSum(vector<int>& nums, int target) {
        //std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        vector<vector<int> > results;
        int i, j, k;
        i=0;
        while(i < n) {
            int a = nums[i];
            int local_target = target - a;
            j = i+1; //left
            k = n-1; //right
            while(j < k) {
                int b = nums[j];
                int c = nums[k];
                if(b + c < local_target) {
                    j++;
                }else if(b + c > local_target) {
                    k--;
                }else{//hit
                    vector<int> result(3);
                    result[0] = a;
                    result[1] = b;
                    result[2] = c;
                    results.push_back(result);

                    while(j<k && nums[j]==b) {
                        j++;
                    }
                    while(j<k && nums[k]==c) {
                        k--;
                    }
                }
            }
            while(i<n && nums[i]==a) {
                i++;
            }
        }
        return results;
    }
};
