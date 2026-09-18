class Solution {
public:
    int divide(int dividend, int divisor) {
        bool testi = false;
        if(dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        if(divisor==1){
            return dividend;
        }

        if ((dividend ^ divisor) < 0) {
            testi = true;
        }
        long long divide = abs((long long)dividend);
        long long divisore = abs((long long)divisor);

        long long ans = 0;
        int x = 0;

        vector<long long> test(34);
        test[x] = divisore;
        while (divide >=divisore) {
            if (test[x] >=divide) {
                while (divide < test[x]) {
                    x--;
                }
                divide -= test[x];
                ans += 1 << x;
            } else {
                if (x < 33) {
                    test[x + 1] = test[x] + test[x];
                    x++;
                }
            }
        }

        if (testi) {
            return -ans;
        }
        return ans;
    }
};