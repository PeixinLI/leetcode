class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	string res = "";
    	int length = strs.size();
    	if(length == 0)
    		return res;

    	int j = 0;
    	while(true){
    		for(int i = 0; i < length; i++){
    			if (j == strs[i].size() || strs[i][j] != strs[0][j]){
    				return res;   		
    			}
    		}
    		res += strs[0][j];
    		j++;
    	}
        
    }
};