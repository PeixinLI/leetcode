//remember vector doesn'r equals to array need to initialize the space
class Solution {
public:
    int nthUglyNumber(int n) {
        // if(n <= 0) return 0；
        if(n == 1) return 1;
        vector<int> ugly_num;
        ugly_num.push_back(1);
        int p2 = 0, p3 = 0, p5 = 0;
        for(int i = 1; i < n; i++){
            int temp = min(ugly_num[p2]*2, min(ugly_num[p3]*3, ugly_num[p5]*5));
            if(temp == ugly_num[p2]*2) p2++;
            if(temp == ugly_num[p3]*3) p3++;
            if(temp == ugly_num[p5]*5) p5++;
            ugly_num.push_back(temp);
            
        }
        return ugly_num[n-1];
        
    }
    int min(int a, int b){
        return a<b? a:b;
    }
};