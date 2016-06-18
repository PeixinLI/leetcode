class Solution {
public:
    vector<int> GrayCode;
    vector<int> grayCode(int n) {
        GrayCode.push_back(0);
        int size = GrayCode.size();
        int i = 0;
        while(i < n){
            for(int j = size - 1; j >= 0; j-- ){
                GrayCode.push_back(GrayCode[j] + (1<< i));
            }
            i++;
            size = GrayCode.size();
        }
        return GrayCode;
    }
    
};