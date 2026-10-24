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
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=0;
        int rh=0;
        TreeNode* temp1=root;
        TreeNode* temp2=root;
        while(temp1!=NULL){
            lh++;
            temp1=temp1->left;
        }
        while(temp2!=NULL){
            rh++;
            temp2=temp2->right;
        }
        if(lh==rh){
            return (1<<lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};