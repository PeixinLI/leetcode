class Solution {
public:
    int maxProduct(vector<int>& nums) {
    	int size = nums.size();

    	int maxProduct = nums[0], minProduct = num[0], res = nums[0];
    	for(int i = 1; i < size; i++){
    		int tmax = maxProduct, tmin = minProduct;
    		maxProduct = max(tmax*nums[i], max(tmin*nums[i], nums[i]));
    		minProduct = min(tmax*nums[i], min(tmin*nums[i], nums[i]));

    		if(res < maxProduct)
    			res = maxProduct;
    	}


    	return res;
 	  
    }
};