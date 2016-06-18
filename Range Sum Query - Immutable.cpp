class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        int sum = 0;
        sums.push_back(sum);
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            sums.push_back(sum);
        }
        
    }

    int sumRange(int i, int j) {
        if(i > j) return 0;
        return sum[j+1] - sum[i];
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);