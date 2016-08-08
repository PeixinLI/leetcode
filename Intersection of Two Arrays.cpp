class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> res;
    	sort(nums1.begin(), nums1.end());
    	sort(nums2.begin(), nums2.end());

    	int size1 = nums1.size();
    	int size2 = nums2.size();

    	int i = 0, j = 0;

    	while(i < size1 && j <size2){
    		if(nums1[i] < nums2[j])
    			i++;
    		else if(nums2[j] < nums1[i])
    			j++;
    		else {
    			if(nums1[i] != res.back()){
    				res.push_back(nums1[i]);
    			}
    			i++;
    			j++;
    		}
    	}

    	return res;
        
    }
};