class Solution {
public:
	int powMod(int a, int k){ // k is a num from 0 to 10
		int t = a % 1337;
		int res = 1;
		for(int i = 0; i < k; i++){
			res = (res * t) % 1337;
		}
		return res;
	} 
	
    int superPow(int a, vector<int>& b) {
    	if(b.empty())
    		return 1;
    	int last = b.back();
    	b.pop_back();

    	return powMod(superPow(a, b), 10) * powMod(a, last) % 1337;        
    }
};