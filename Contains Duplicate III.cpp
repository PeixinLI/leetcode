// int overflow ????

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long, int>> dup_num;
        int L = nums.size();
        
        if(L <= 1) return 0;
        
        for(int i = 0; i < L; i++)
            dup_num.push_back (pair<long, int>(nums[i], i));
        
        sort(dup_num.begin(), dup_num.end(), greater);
        
        for(int i = 0; i < L; i++){
            int j = i + 1;
            while( (dup_num[j].first - dup_num[i].first) <= t && j < L){
                if((dup_num[j].second - dup_num[i].second) <= k
                   && (dup_num[j].second - dup_num[i].second) >= -k ) return true;
                j++;
            }
        }
        return false;
    }
    
    static bool greater(pair<long, int> a, pair<long, int> b){
        return (a.first < b.first) ? true:false;
    }
};

/// ??? static?
//multimap