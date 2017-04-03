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
    map<int, int> _map;
public:
    vector<int> findMode(TreeNode* root) {
        map<int, vector<int>> _rmap;
        _rmap[0];
        
        count(root);
        
        for(auto i: _map){
            _rmap[i.second].push_back(i.first);
        }
        
        return _rmap.rbegin()->second;
    }
    void count(TreeNode* node){
        if(!node){
            return;
        }
        _map[node->val] ++;
        count(node->left);
        count(node->right);
    }
};
