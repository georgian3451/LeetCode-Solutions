class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=baskets.size();
        vector<bool>used(n,false);
        int unplaced=0;
        for(int f:fruits){
            int idx=-1;
            for(int j=0;j<n;j++){
                if(!used[j] && baskets[j]>=f){
                    idx=j;
                    break;
                }
            }
            if(idx==-1) unplaced++;
            else used[idx]=true;
        }
        return unplaced;
    }
};