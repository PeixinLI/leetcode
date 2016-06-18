class Solution {
public:
    vector<vector<int>> subset_Dup;
    vector<int> subset;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int N = nums.size();
        if(N == 0) return subset_Dup;
        
    }
    
    void find_subset(int k , int begin, int end, vector<int>& nums){
        if(begin + k -1 > end) return;
        if(k < 0) return;
        if(k == 0){
            subset_Dup.push_back(subset);
            return 0;
        }
        int i = begin;
        while(nums[i] == nums[begin]) i++;
        
        for(int j = 0; j <= i-begin ; i++){
            if(j > 0)
            subset.push_back(nums[begin]);
            find_subset(k - j, i, end, nums);
        }
        
        for(int j = 0; j < i-begin ; i++)
            subset.pop_back();
        
        
        return;
        
    }
};
//reference
/*    class Solution {
 public:
 vector<vector<int> > subsetsWithDup(vector<int> &S) {
 vector<vector<int> > totalset = {{}};
 sort(S.begin(),S.end());
 for(int i=0; i<S.size();){
 int count = 0; // num of elements are the same
 while(count + i<S.size() && S[count+i]==S[i])  count++;
 int previousN = totalset.size();
 for(int k=0; k<previousN; k++){
 vector<int> instance = totalset[k];
 for(int j=0; j<count; j++){
 instance.push_back(S[i]);
 totalset.push_back(instance);
 }
 }
 i += count;
 }
 return totalset;
 }
 };*/