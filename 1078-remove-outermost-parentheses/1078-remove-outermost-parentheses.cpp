class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int n=S.length();
        int c=0;
        for(int i=0;i<n;i++){
            if(S[i]=='('){
                if(c>0)res+=S[i];
                c++;
            }
            else if(S[i]==')'){
                c--;
                if(c>0)res+=S[i];
            }
            
        }
        return res;
    }
};