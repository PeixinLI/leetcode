class Solution {
public:
    int countNumbersWithUniqueDigits(int n){
        if(n == 0)
            return 1;

        if(n > 10)
            n = 10;

        int res = 10;
        int permutation = 1;

        for(int i = 1; i < n; i ++){
            permutation *= 10 - i;
            res += 9 * permutation;
        }

        return res;

    }

};