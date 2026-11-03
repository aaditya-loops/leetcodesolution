class Solution {
public:
    int countPrimes(int n) {
        int count=0;
        vector<bool> isprime(n+1,true);
        for(long long i=2;i<n;i++){
            if(isprime[i]){
                count++;
                for(long long j=i*i;j<n;j=j+i){
                    isprime[j]=false;
                }
            }

        }
        return count;
    }
};