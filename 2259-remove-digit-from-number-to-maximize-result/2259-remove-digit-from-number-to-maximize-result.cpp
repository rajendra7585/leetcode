class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string ans;
        string maxans="";
        for(int i=0;i<n;i++){
            ans="";
            if(number[i]==digit){
               ans+=number.substr(0,i)+number.substr(i+1,n);
               
               if(ans>maxans){
                maxans=ans;
               }
            }
        }
        return maxans;
    }
};