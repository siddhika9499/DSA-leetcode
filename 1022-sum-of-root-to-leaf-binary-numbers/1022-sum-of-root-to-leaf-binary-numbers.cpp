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
    int dfs(TreeNode* root, string path){
        if(root == NULL) return 0;
        path += to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            return stoi(path,nullptr,2);
        }
        return dfs(root->left, path)+dfs(root->right,path);
    }
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root,"");
    }
};