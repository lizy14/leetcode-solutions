/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_multiset<int> sums;
    bool checkEqualTree(TreeNode* root) {
        sums.clear();
        auto sum = getSum(root);
        
        // check if `sum` and `sum / 2` are both in `sums`
        if(sum != 0){
            return sum % 2 == 0 && sums.find(sum / 2) != sums.end();
        }else{
            return sums.count(0) >= 2;
        }
    }
    int getSum(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        auto sum = root->val + getSum(root->left) + getSum(root->right);
        sums.insert(sum);
        return sum;
    }
};
