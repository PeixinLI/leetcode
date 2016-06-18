/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int L = nums.size();
        sort(nums.begin(), nums.end());
        return nums[L-k];
        
    }
};*/

//second try doesn't work
/*class Solution {
public:
    int findKthLargest( vector<int>& nums, int k) {
        int t = -1;
        int L = (int)nums.size();
        int begin = 0;
        int end = L-1;
        while(t != k-1){
            t = partition(begin, end, nums);
            if(t > k-1) end = t - 1 ;
            if(t < k-1) begin = t + 1;
        }
        
        cout<<"result: "<<nums[t]<<endl;
        return nums[t];
    }
    
    int partition (int begin, int end, vector<int> & nums){
        int i = begin ;
        int j = end;
        int key = nums[begin];
        if (i == j) {
            return i;
        }
        while( i <= j ){
            while(nums[j] < key){
                j--;
            }
            
            while(nums[i] > key){
                i++;
            }
            if( i <= j){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                i++;
                j--;
            }
        }
        return i;
    }
};*/


class Solution {
public:
    int findKthLargest( vector<int>& nums, int k) {
        return partition(0, nums.size(), k ,nums);
    }
    
    int partition (int begin, int end, int k, vector<int> & nums){
        if(begin == end) return begin;
        int i = begin;
        int j = end;
        int L = nums.size();
        int key = nums[i]
        while( i <= j ){
            while(nums[j] < key) j--;
            while(nums[i] > key) i++;
            if(i <= j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
                j--;
            }
        }
        if( i > k) return partition(begin, i, k, nums);
        if( j < k) return partition(j, end, k, nums)
        return nums[j+1];
    }
    
};