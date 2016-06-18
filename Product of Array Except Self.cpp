class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	vector<int> out;
    	int a=1, num=nums.size();
    	
    	for(int i=0; i<num; i++){
    		out.push_back(a);//out[i] = a;
    		a *= nums[i];
    		}
    		
    		a=1;
    	for(int i=n-1; i>=0; i--){
    		out[i] *= a;
    		a *= nums[i];
    		}
    		
    	return out;
        
    }
};