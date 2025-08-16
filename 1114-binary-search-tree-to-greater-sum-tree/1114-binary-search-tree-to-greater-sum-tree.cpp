/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int sum=0;
    void reverseinorder(TreeNode* root){
        if(root==NULL)return ;
        reverseinorder(root->right);
        root->val+=sum;
        sum=root->val;
        reverseinorder(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        reverseinorder(root);
        return root;
    }
};