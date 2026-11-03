class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=1){
            return false;
        }
        long long x = 1;
        int p = 0;
        long long y = 0;
        while (y < num) {
            p++;
            x = 1ll << p;

            y = (x / 2)*(x - 1);
        }
        if (y == num) {
            
            for (int i = 2; i * i <= p; i++) {
                if (p % i == 0) {
                    return false;
                }
            }
            x=x-1;
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};