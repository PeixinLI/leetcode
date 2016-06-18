class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";
        if(n == 0) return s;
        
        vector<int> nums;
        for(int i = 1; i<= n;i++) nums.push_back(i);
        
        // calcualte n-1 factorial;
        int * fn = new int[n];
        fn[0] = 1;
        for(int i = 0; i < n-1; i++){
            fn[i] *= i+1;
        }
        k--;
        for(int i = 0; i < n - 1; i++){
            int j = i + k / fn[n - 2 - i];
            if(i == j){
                k = k % fn[n - 2 - i]; //wr
                continue;
            }
            swap(nums[i], nums[j]);
            int t = nums[j];
            for(int m = j; m > i; m--)
                nums[m] = nums[m - 1];
            nums[i+1] = t;
            k = k % fn[n - 2 - i];
        }
        
        for(int i = 0; i < n; i++)
            s += '0'+ nums[i];
        
        return s;
        
    }
};