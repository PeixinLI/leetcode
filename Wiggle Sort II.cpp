class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int L = nums.size();
        if(L == 0 || L == 1)
          return ;
        sort(num.begin(), num.end());
        for(int i = 0; i < L/2; i++){
            nums[k] = sort_num[i];
            i++;
            k++;
            if( k < L) {
                nums[k] = sort_num[j];
                j++;
                k++;
            }
        }

    }
};

// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         int L = nums.size();
//         for(int i = 0; i < L-1; i++){
//             if( (i % 2 == 0 && nums[i] > nums[i+1]) || (i % 2 == 1 && nums[i] < nums[i+1]){
//                 int temp = nums[i];
//                 nums[i] = nums[i+1];
//                 nums[i+1] = temp;
//             }
//         }
//     }
// };
