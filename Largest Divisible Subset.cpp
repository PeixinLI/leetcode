class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int size = nums.size();

    	vector<int> setSize(size, 0);
    	vector<int> lastNum(size, 0);

    	int max_num = 0;
    	int max_i = 0;
    	for(int i = 0; i < size; i ++){
    		for(int j = i; j < size; j ++){

    			if(nums[j] % nums[i] == 0 && setSize[j] < setSize[i] + 1){
    				setSize[j] = setSize[i] + 1;
    				lastNum[j] = i;

    				if(setSize[j] > max_num){
    					max_num = setSize[j];
    					max_i = j;
    				}
    			}
    		}
    	}

    	vector<int> res;

    	for(int i = 0; i < max_num; i++){
    		res.push_back(nums[max_i]);
    		max_i = lastNum[max_i];
    	}

    	return res;
        
    }
};