class Solution {
public:
    string countOfAtoms(string formula){
        int n=formula.size();
        int i=0;

        vector<map<string,long long>> stack;
        stack.push_back({});
        while (i<n){
            char c = formula[i];

            if (c=='('){
                stack.push_back({});
                i++;
            } else if (c==')'){
                i++;
                int start=i;
                while (i<n && isdigit(formula[i])){
                    i++;
                }
                long long mult = (start==i) ? 1 : stoll(formula.substr(start,i-start));

                map<string,long long> top=stack.back();
                stack.pop_back();

                for (auto& [name,cnt] : top) {
                    stack.back()[name] += cnt*mult;
                }
            } else {
                int start=i;
                i++;
                while (i<n && islower(formula[i])) i++;
                string name = formula.substr(start,i-start);

                int numStart=i;
                while (i<n && isdigit(formula[i])) i++;
                long long cnt = (numStart==i) ? 1 : stoll(formula.substr(numStart,i-numStart));

                stack.back()[name]+= cnt;
            }
        }

        map<string, long long> result = stack.back();

        string ans;
        for (auto& [name,cnt] : result) {
            ans+= name;
            if (cnt>1) ans += to_string(cnt);
        }

        return ans;
    }
};