class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        
        for(int i=0;i<nums1.size();i++){
            int k=-1;
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    while(j<nums2.size()){
                        if(nums1[i]<nums2[j]){
                            ans.push_back(nums2[j]);
                            k=1;

                            break;

                        }
                        j++;
                    }
                    if(k==-1)ans.push_back(-1);
                    break;
                }
            }
        }
        return ans;
    }
};