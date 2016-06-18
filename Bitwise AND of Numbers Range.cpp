class Solution {
public:
    //This solution just calculate the unchanged bit part juring the bitwise-and all numbers between m and n.Cause m and n is the min and max number in the range,so their unchanged part will be the same in other numbers in the range.
    //you only need to judge when the left highest bits are the same and return them
    int rangeBitwiseAnd(int m, int n) {
        int same_bit = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            same_bit ++;
        }
        return m << same_bit;
    }
};

//second solution

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        return (m!=n) ? rangeBitwiseAnd(m>>1, n>>1) <<1 : m;
        
    }
};