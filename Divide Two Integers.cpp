class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ans = 0;
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        cout <<a<<" "<<b<<endl;
        while(a >= b){
            long long t = 1;
            long long tb = b;
            while((tb << 1) < a) {
                tb <<= 1;
                t <<= 1;
            }
            a -= tb;
            ans += t;
        }
        
        if((dividend < 0 && divisor > 0)||(dividend > 0 && divisor <0))
            ans = -ans;
        if(ans <= 2147483647 && ans >= -2147483648)
            return ans;
        return 2147483647;
    }
};

//second solution