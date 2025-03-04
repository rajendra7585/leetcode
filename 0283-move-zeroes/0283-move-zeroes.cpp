class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int l = nums.size();
        if( l == 1 ) return ; 
        for( int i = 0 ; i < l ; i++ ){
            if( nums[ i ] != 0 ){
                nums[ index ] = nums[ i ];
                if( i != index )
                    nums[ i ] = 0;
                index++;
            }
        }
    }
};