class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(number[i]==digit){
                if(i+1<n && number[i]<number[i+1]){
                idx=i;
                break;
            }}
        }
        if(idx==-1){
            for(int i=n-1;i>=0;i--){
                if(number[i]==digit){
                    idx=i;
                    break;
                }
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(i!=idx){
               ans+=number[i];
            }
        }
        return ans;
    }
};