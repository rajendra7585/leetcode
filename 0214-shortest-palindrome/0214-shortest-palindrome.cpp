class Solution {
public:
    string shortestPalindrome(string s) {
        const string t={s.rbegin(),s.rend()};
        const string_view sv(s);
        const string_view tv(t);
        for(int i=0;i<s.length();i++){
            if(sv.substr(0,s.length()-i)==tv.substr(i)){
                return t.substr(0,i)+s;
            }
        }
        return t+s;
    }
};