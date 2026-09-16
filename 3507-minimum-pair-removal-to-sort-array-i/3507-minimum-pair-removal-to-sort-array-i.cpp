class Solution {
public:
    int minimumPairRemoval(vector<int>&nums) {
        vector<long long>a(nums.begin(), nums.end());
        int ops=0;

        auto isSorted=[&]() {
            for(int i=1; i<(int)a.size(); i++)
                if(a[i]<a[i-1]) return false;
            return true;
        };

        while(!isSorted()) {
            int n=a.size(), idx=0;
            long long best=LLONG_MAX;
            for(int i=0; i+1<n; i++) {
                long long temp1=a[i]+a[i+1];
                if(temp1<best) { best=temp1; idx=i; }
            }
            a[idx]=a[idx]+a[idx+1];
            a.erase(a.begin()+idx+1);
            ops++;
        }
        return ops;
    }
};