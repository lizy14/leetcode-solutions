class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        vector<int> u = candies;
        u.erase(unique(u.begin(), u.end()), u.end()); 
        return min(u.size(), candies.size() / 2);
    }
};
