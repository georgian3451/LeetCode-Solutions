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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL){
            cout<<"Tree is empty"<<endl;
            return -1;
        }
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* cur=root;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            if(cur->right!=NULL){
                q.push(cur->right);
            }
            if(cur->left!=NULL){
                q.push(cur->left);
            }
        }
        return cur->val;
    }
};