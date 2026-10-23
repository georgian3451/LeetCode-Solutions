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
    TreeNode* findMin(TreeNode* cur){
        while(cur->left!=NULL){
            cur=cur->left;
        }
        return cur;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL;
        }
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
        
            if(root->left==NULL){
                TreeNode* temp1=root->right;
                delete root;
                return temp1;
            }
            if(root->right==NULL){
                TreeNode* temp2=root->left;
                delete root;
                return temp2;
            }
        
            TreeNode* temp1=findMin(root->right);
            root->val=temp1->val;
            root->right=deleteNode(root->right,temp1->val);
        }
        return root;
    }
};