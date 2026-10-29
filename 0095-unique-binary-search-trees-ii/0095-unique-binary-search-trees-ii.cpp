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
    vector<TreeNode*> build(int low,int high){
        vector<TreeNode*>ans;
        if(low>high){
            ans.push_back(nullptr);
            return ans;
        }
        for(int i=low;i<=high;i++){
            vector<TreeNode*>temp1=build(low,i-1);
            vector<TreeNode*>temp2=build(i+1,high);
            for(int j=0;j<temp1.size();j++){
                for(int k=0;k<temp2.size();k++){
                    TreeNode* cur=new TreeNode(i);
                    cur->left=temp1[j];
                    cur->right=temp2[k];
                    ans.push_back(cur);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0){
            return {};
        }
        return build(1,n);
    }
};