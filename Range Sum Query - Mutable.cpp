class NumArray {
public:
	vector<int>* sum;
	vector<int> arr;
	int size;
    NumArray(vector<int> &nums) {
        size = nums.size()+1;
        sum = new vector<int>(size+1,0);
        arr = nums;
        (*sum)[0] = 0;
    	for(int i = 1; i < size; i++){
    		(*sum)[i] = nums[i-1] + (*sum)[i-1];
    	}
    }

    void update(int i, int val) {
        int dif = val - arr[i];
        arr[i] = val;
        for(int j = i+1; j < size; j++){
        	(*sum)[j] += dif;
        }
    }

    int sumRange(int i, int j) {
    	return (*sum)[j+1] - (*sum)[i];    
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);