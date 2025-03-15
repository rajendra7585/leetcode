class Solution {
public:
    int countPrimes(int n) {
         vector<bool>isPrime(n+1,true);
        isPrime[0]=false;
        isPrime[1]=false;
        int c=0;
        for(int i=2;i*i<=n;i++){
            if(isPrime[i]==true){
                for(int j=2;j*i<=n;j++){
                    isPrime[i*j]=false;
                }
            }
        }
       
     
        for(int i=2;i<n;i++){
            
            if((isPrime[i]==true)) c++;;
        }
        return c;
    }
};