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
    bool check(TreeNode* node,long long low,long long high){
        if(node==NULL){
            return true;
        }
        if(node->val<=low || node->val>=high){
            return false;
        }
        bool temp1=check(node->left,low,node->val);
        if(temp1==false){
            return false;
        }
        bool temp2=check(node->right,node->val,high);
        return temp2;
    }

    bool isValidBST(TreeNode* root) {
        return check(root,LLONG_MIN,LLONG_MAX);
    }
};