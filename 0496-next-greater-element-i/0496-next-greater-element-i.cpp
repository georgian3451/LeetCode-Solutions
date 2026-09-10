class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nge;
        stack<int>stk;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=nums2[i]){
                stk.pop();
            }
            nge[nums2[i]]= stk.empty() ? -1 : stk.top();
            stk.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();i++){
            ans[i]=nge[nums1[i]];
        }
        return ans;
    }
};