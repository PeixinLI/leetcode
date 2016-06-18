/*class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        vector<int> bulk(n, 0);
        for(int i = 1 ; i <= n; i++){ // the round number
            for(int j = 1; j<= n/i; j++)
                bulk[i*j -1] = !bulk[i*j -1];
        }
        int on = 0;
        for(int i = 0; i < n; i++){
            if(bulk[i]) on++;
        }
        return on;
        
    }
};*/
//first way is time limited exceeded

//second way
//The final state of a light is on and off only depends on if the number of its factor is odd or even. If odd, the light is on and if even the light is off. The number of one number's factor is odd if and only if it is a perfect square!

class Solution {
public:
    int bulbSwitch(int n) {
        if(n == 0) return 0;
        int count = 0;
        for(int i = 1; i*i <= n; i++)
            count++;
        
        return count;
        
    }
};

//third way faster
/*
 int bulbSwitch(int n) {
 long long lo = 0, hi = n, mid;
 while (lo < hi) {
 mid = lo + (hi - lo + 1) / 2;
 if (mid * mid <= n)
 lo = mid;
 else
 hi = mid - 1;
 }
 return lo;
 }*/