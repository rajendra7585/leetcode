class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.length();
        string a,b;
        int count=0;

        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                count++;
                a.push_back(s1[i]);
                b.push_back(s2[i]);
                
            }
        }
        if(count>2)return false;
        else if(a[0]!=b[1] || a[1]!=b[0])return false;
        else return true;
        
    }
};