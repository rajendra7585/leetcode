class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int maxlen=0;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int it:st){
            int x=it;
            if(st.find(x-1)==st.end()){
                int count=1;
                while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                }
                maxlen=max(maxlen,count);
            }
            
        }
        return maxlen;
    }
};