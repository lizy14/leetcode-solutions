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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        auto paths = _pathSum(root, sum);
        for(auto& path: paths){
            reverse(path.begin(), path.end());
        }
        return paths;
    }
    vector<vector<int>> _pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        if(root->left == nullptr && root->right == nullptr){
            if(root->val == sum){
                vector<int> path;
                path.push_back(root->val);
                result.push_back(path);
            }
            return result;
        }
        sum -= root->val;
        auto left = _pathSum(root->left, sum);
        auto right = _pathSum(root->right, sum);
        for(auto path: left){
            path.push_back(root->val);
            result.push_back(path);
        }
        for(auto path: right){
            path.push_back(root->val);
            result.push_back(path);
        }
        return result;
        
    }
};
