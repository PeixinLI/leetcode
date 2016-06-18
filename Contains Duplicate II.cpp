class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        
        map<int,int> dup_map;
        
        int L = nums.size();
        
        if(L <= 1) return 0;
        
        for(int i = 0; i < L; i++){
            if(dup_map.count(nums[i]) && (i - dup_map[nums[i]]) <= k) return true;
            dup_map[nums[i]] = i;
        }
        
        return false;
        
    }
};