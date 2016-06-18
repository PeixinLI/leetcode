class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
    vector<string> result;
    int size = nums.size();
    if(size == 0) return result;
    
    int rp = nums[0], lp = nums[0];
    for(int i=1 ; i<size ; i++){     
      if(nums[i] == (rp +1)){
      	rp = nums[i];
      }
      else{
      	string temp;
      	if(rp > lp) temp = to_string(lp) + "->" + to_string(rp); 
      	else if(rp == lp) temp = to_string(lp);
      	result.push_back(temp);
      	lp = nums[i];
      	rp = lp;
      }
    }
    
    string temp;
    if(rp > lp) temp = to_string(lp) + "->" + to_string(rp); 
    else if(rp == lp) temp = to_string(lp);
    result.push_back(temp);
    
    
    return result;
        
    }
};