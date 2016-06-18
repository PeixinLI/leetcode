//First try: Time Limit Exceeded
/*class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int> dup_num;
        int length = nums.size();
        
        for(int i = 0 ; i < length; i++ ){
            vector<int>::iterator it;
            
            it = find(dup_num.begin(), dup_num.end(), nums[i]);
            if(it != dup_num.end())
                return true;
            
            else dup_num.push_back(nums[i]);
            
            
        }
        
    }
};*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> dup_num;
        for (int i = 0; i<nums.size(); i++) {
            if(dup_num.count(nums[i])){
                return true;
            }
            dup_num.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};

//std::set s(nums.begin(), nums.end()); return s.size() != nums.size();