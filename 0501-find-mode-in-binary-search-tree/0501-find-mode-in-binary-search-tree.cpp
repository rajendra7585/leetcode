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
    
   void helper(TreeNode* root,unordered_map<int,int>&m){
    if(root==NULL)return;
    helper(root->left,m);
    m[root->val]++;
    helper(root->right,m);
   }
   
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>m;
        helper(root,m);
        int maxi=0;
        for(const auto i:m){
          maxi=max(maxi,i.second);
        }
        vector<int>ans;
        for(const auto i:m){
            if(i.second==maxi)ans.push_back(i.first);
        }
        return ans;
    }
};