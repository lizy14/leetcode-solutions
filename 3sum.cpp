class Solution {
    public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > results;
        int i, j, k;
        i=0;
        while(i < n) {
            int a = nums[i];
            int target = 0 - a;
            j = i+1; //left
            k = n-1; //right
            while(j < k) {
                int b = nums[j];
                int c = nums[k];
                if(b + c < target) {
                    j++;
                }else if(b + c > target) {
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
