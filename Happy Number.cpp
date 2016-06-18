class Solution {
public:
    bool isHappy(int n) {
        vector<int> exist;
        while(n){
            if(find(exist.begin(), exist.end(), n) != exist.end()) return false;
            int t = 0;
            while(n){
                t += (n%10) * (n%10);
                n = n/10;
            }
            n = t;
            exist.push_back(n);
        }
        
        return false;
        
    }
};


//math solution
class Solution {
public:
    bool isHappy(int n) {
       // map<int> exist;
        while(n){
            if( n == 4 ) return false;
            if( n == 1) return true;
            int t = 0;
            while(n){
                t += (n%10) * (n%10);
                n = n/10;
            }
            n = t;
        }
        
        return false;
        
    }
};