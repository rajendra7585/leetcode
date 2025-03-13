class Solution {
public:
    vector<int> singleNumber(vector<int>& Arr) {
        long long int x = 0;
        int bucket1 = 0, bucket2 = 0;
        long long int N=Arr.size();
        
        for (long long int i = 0; i < N; i++) {
            x ^= Arr[i];
        }
    
        long long int num =x & x-1;
        num = num ^ x;
        
        
    
        for ( long long int i = 0; i < N; i++) {
            if (Arr[i] & num) bucket1 ^= Arr[i];
            else bucket2 ^= Arr[i];
        }
    
        if (bucket1 < bucket2) swap(bucket1, bucket2);
        
        
        return {bucket1, bucket2};
    }
};