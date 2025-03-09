class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.length();
        string ans;
        int idx;
        for(int i=n-1;i>=0;i--){
             if(num[i]%2!=0){
                 idx=i;
                 break;
             }
        }
        for(int i=0;i<=idx;i++){
            ans+=num[i];

        }
        return ans;
    }
};