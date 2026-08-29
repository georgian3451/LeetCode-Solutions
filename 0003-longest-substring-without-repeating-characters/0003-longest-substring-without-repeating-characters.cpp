class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>lastSeen;
        int maxlen=0;
        int start=0;
        for(int end=0;end< s.size();end++){
            char c=s[end];
            if(lastSeen.find(c)!=lastSeen.end()&&lastSeen[c]>=start){
                start=lastSeen[c]+1;
            }
            lastSeen[c]=end;
            maxlen=max(maxlen,end-start+1);
        }
        return maxlen;
        
    }
};