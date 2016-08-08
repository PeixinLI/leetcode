// class Solution {
// public:
//     vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//     	vector<pair<int, int>> res;
    	

//     	int size1 = nums1.size();
//     	int size2 = nums2.size();
//     	if(k == 0 || size1 ==0 || size2 == 0)
//     		return res;

//     	int i = 0, j = 0;

//     	res.push_back(pair<int,int>(nums1[i], nums2[j]));
//     	int n = k-1;
//     	while(n-- && !(i == size1 - 1 && j == size2 - 1)){
//     		if(i < size1 -1 && j < size2 -1){
//     			if((nums1[i] + nums2[j+1]) < (nums1[i+1] + nums2[j])){
//     				res.push_back(pair<int, int>(nums1[i], nums2[++j]));
//     			}
//     			else if(){
//     				res.push_back(pair<int, int>(nums1[++i], nums2[j]));
//     			}
//     		}
//     		else if(i == size1 - 1)
//     			res.push_back(pair<int, int>(nums1[i], nums2[++j]));
    		
//     		else if(j == size2 - 1)
//     			res.push_back(pair<int, int>(nums1[++i], nums2[j]));
//     	}

//     	return res;
    	
//     }
// };
//Doesn't work

class Solution {
public:
struct cmp
{
	bool operator()(pair<int, int> a, pair<int, int>b){
		return (a.first + a.second) > (b.first + b.second);
	}
	
};
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    	int size1 = nums1.size();
    	int size2 = nums2.size();
    	vector<pair<int, int>> res;

    	if(k == 0 || size1 == 0|| size2 ==0)
    		return res;

    	priority_queue< pair<int, int>, vector<pair<int,int>>, cmp > q;

        for(int i = 0; i < min(size1, k) ; i++)
        	for(int j = 0; j < min(size2, k); j++){
        		q.push(pair<int, int>(nums1[i], nums2[j]));
        	}

        while(!q.empty() && k--){
        	pair<int, int> tmp = q.top();
        	q.pop();
        	res.push_back(tmp);
        }
        return res;
    }
};




