class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int p=k;
        int maxlen=0;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(k==0){
                    start=i+1;
                    continue;
                }
                if(p>0){
                    p--;
                    q.push(i);
                }
                else{
                    start=q.front()+1;
                    q.pop();
                    q.push(i);
                }
            }
            maxlen=max(maxlen,i-start+1);
        }
        return maxlen;
    }
};