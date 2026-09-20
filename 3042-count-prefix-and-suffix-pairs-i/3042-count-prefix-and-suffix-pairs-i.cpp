class Solution {
public:
    bool isPrefixAndSuffix(string a, string b){
        int n=a.size(), m=b.size();
        if(n>m) return false;
        return b.substr(0,n)==a && b.substr(m-n,n)==a;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};