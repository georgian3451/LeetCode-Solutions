class Solution {
public:
    long long countCommas(long long n){
        long long total=0;
        long long lo=1;
        long long hi=9;
        int d=1;
        while (lo<=n) {
            long long upper = std::min(hi,n);
            long long count = upper-lo+1;
            long long commasPer =(d-1)/3;
            total += count*commasPer;
            d++;
            lo=hi+1;
            if (hi>(long long)4e18){
                break;
            }
            hi = hi*10+9;
        }
        return total;
    }
};