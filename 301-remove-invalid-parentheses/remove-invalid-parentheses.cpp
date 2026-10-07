class Solution {
    vector<string> ans;
    string s;

    void dfs(int start,int l,int r) {
        if(l==0&&r==0){
            int bal=0;
            for(char c:s){
                if(c=='(') bal++;
                else if(c==')'){
                    bal--;
                    if(bal<0) return;
                }
            }
            if(bal==0)
                ans.push_back(s);
            return;
        }

        for(int i=start;i<s.size();i++){
            if(i>start&&s[i]==s[i-1])
                continue;

            if(l>0&&s[i]=='('){
                string t=s;
                s.erase(i,1);
                dfs(i,l-1,r);
                s=t;
            }

            if(r>0&&s[i]==')'){
                string t=s;
                s.erase(i,1);
                dfs(i,l,r-1);
                s=t;
            }
        }
    }

public:
    vector<string> removeInvalidParentheses(string str) {
        s=str;
        ans.clear();

        int l=0,r=0;
        for(char c:s){
            if(c=='(')
                l++;
            else if(c==')'){
                if(l>0)
                    l--;
                else
                    r++;
            }
        }

        dfs(0,l,r);
        return ans;
    }
};