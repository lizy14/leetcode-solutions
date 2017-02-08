class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result(3);
        int sum = 0;
        int i;
        for(i=0; i<3; i++){
            sum += (result[i] = nums[i]);
        }
        int margin = abs(target - sum);
        
        int n = nums.size();
        
        i = 0;
        while(i < n){
            int a = nums[i];
            
            int j = i+1;
            int k = n-1;
            
            while(j < k){
                int b = nums[j];
                int c = nums[k];
                sum = a+b+c;
                if(sum <= target - margin){
                    j++;
                }else if(sum >= target + margin){
                    k--;
                }else{//hit
                    result[0] = a;
                    result[1] = b;
                    result[2] = c;
                    margin = abs(target - sum);
                }
            }
            i++;

        }
        return result[0] + result[1] + result[2];
    }
};
