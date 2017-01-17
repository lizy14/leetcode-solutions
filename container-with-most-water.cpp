class Solution {
public:
    int maxArea(vector<int>& height) {
        auto n = height.size();
        int r = 0;
        int i = 0, j = n-1;
        while(i<j){
            if(height[i] > height[j]){
                r = max(r, height[j] * (j-i));
                j--;
            }else{
                r = max(r, height[i] * (j-i));
                i++;
            }
        }
        return r;
    }
};
