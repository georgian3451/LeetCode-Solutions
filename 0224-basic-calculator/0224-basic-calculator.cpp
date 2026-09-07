class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result=0;
        int sign=1;
        int n=s.size();
        int i=0;
        
        while(i<n){
            char c = s[i];
            if(isdigit(c)){
                long num=0;
                while(i<n && isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                result+= sign * num;
                continue;
            } else if(c == '+'){
                sign=1;
                i++;
            } else if(c=='-'){
                sign=-1;
                i++;
            } else if(c=='('){
                st.push(result);
                st.push(sign);
                result=0;
                sign=1;
                i++;
            } else if(c==')'){
                int prevSign=st.top(); st.pop();
                int prevResult=st.top(); st.pop();
                result = prevResult+prevSign*result;
                i++;
            } else{                
                i++;
            }
        }        
        return result;
    }
};