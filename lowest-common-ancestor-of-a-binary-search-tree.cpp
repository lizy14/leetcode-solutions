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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr){
            return root;
        }
        
        int pval = p->val;
        int qval = q->val;
        int rval = root->val;
        
        if (pval < rval && qval < rval){
            // root > both
            return lowestCommonAncestor(root->left, p, q);
        }else if(pval > rval && qval > rval){
            // root < both
            return lowestCommonAncestor(root->right, p, q);
        }else{
            // root in between
            return root;    
        }
    }
};
