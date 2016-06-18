class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> result;
    	int size = nums.size();
    	int n1 = nums[0], n2 = nums[0], count1 = 0, count2 = 0;
    	for(int i = 0; i < size; i++){
    		
    		if(count1 == 0 || n1 == nums[i]){
    			n1 = nums[i];
    			count1++;
    			}
    			
    		else if(count2 == 0 || n2 == nums[i]){
    			n2 = nums[i];
    			count2++;
    			}
    			
    		else {
    			count1--;
    			count2--;
    			}
    		}
    		
    	count1 = 0;
    	count2 = 0;
    	
    	for(int i =0; i < size ; i++){
    		if(nums[i] == n1) count1 ++;
    		else if(nums[i] == n2) count2 ++;
    		}
    		
    	if(count1 > size/3) result.push_back ( n1 );
    	if(count2 > size/3) result.push_back ( n2 );
        return result;
    }
    
};