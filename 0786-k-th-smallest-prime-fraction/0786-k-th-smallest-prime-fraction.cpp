class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        double lo=0, hi=1;

        while(lo<hi){
            double mid=(lo+hi)/2;
            int cnt=0,p=0,q=0;
            double maxFrac=0;

            int j=1;
            for(int i=0;i<n-1;i++){
                while(j<n && arr[i] > mid*arr[j]) j++;
                cnt += (n-j);
                if(j<n){
                    double frac=(double)arr[i]/arr[j];
                    if(frac>maxFrac){
                        maxFrac=frac;
                        p=i;
                        q=j;
                    }
                }
            }

            if(cnt==k){
                vector<int>ans(2);
                ans[0]=arr[p];
                ans[1]=arr[q];
                return ans;
            }
            else if(cnt<k) lo=mid;
            else hi=mid;
        }
        return {};
    }
};