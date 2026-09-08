class Solution {
public:
    int countCommas(int n){
        int total=0;
        for (int k=1;k<=n;++k){
            int len = std::to_string(k).size();
            total += (len-1)/3;
        }
        return total;
    }
};