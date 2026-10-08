class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        int cnt=0;
        for(char c:s){
            if(c=='('){
                if(cnt>0)
                    result+=c;
                cnt++;
            }else{
                cnt--;
                if(cnt>0)
                    result+=c;
            }
        }
        return result;
    }
};