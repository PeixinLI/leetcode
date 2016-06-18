class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int k = (m + n + 1) /2;
        double med = (double) findkth(nums1, nums2, 0, m , 0, n , k);
        cout<<med<<endl;
        if((m + n) % 2 == 0){
            double med2 = (double) findkth(nums1, nums2, 0, m , 0, n , k+1);
            cout << med2 <<endl;
            med = (med + med2)/2;
        }
        
        return med;
        
    }
    
    int findkth(vector<int> & nums1, vector<int>& nums2, int begin1, int size1, int begin2, int size2, int k){
        cout << size1 << " "<< size2<<endl;
        if(size1 > size2){
            return findkth(nums2, nums1, begin2, size2, begin1, size1, k);
        }
        
        if(size1 == 0) // if its the end of the nums1 then we find the kth smallest num in nums2
            //cout<<nums2[0]<<endl;
            return nums2[k-1];
        
        
        if(k == 1)
            return min(nums1[begin1], nums2[begin2]);
        
        int k1 = min(k/2, size1); // k1            n -k1
        int k2 = k - k1; //          k - k1        m - ( k - k1)
        // left  k   right m + n - k
        if(nums1[begin1 + k1 - 1] < nums2[begin2 + k2 - 1]) // then the kth smallest is in the right sid
            return findkth(nums1, nums2, begin1 + k1, size1 - k1, begin2, size2, k - k1);
        
        return findkth(nums1, nums2, begin1, size1, begin2 + k2, size2 - k2, k - k2);
    }
    
};