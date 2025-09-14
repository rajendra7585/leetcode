class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        for(char c:t){
            need[c]++;
        }
        
        int have=0;
        int left=0;
        int start=0;
        int max_len=INT_MAX;
        for(int right=0;right<s.size();right++){
            char c=s[right];
            
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c]){
                    have++;
                }
            }
            while(have==need.size()){
                if(right-left+1<max_len){
                    max_len=right-left+1;
                    start=left;
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d])have--;
                    window[d]--;
                }

            }
        }
        return max_len== INT_MAX ? "" : s.substr(start, max_len);


    }
};