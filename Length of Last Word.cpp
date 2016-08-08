class Solution {
public:
    int lengthOfLastWord(string s) {
    	int len = s.size();

    	if(len == 0)
    		return 0;

    	int i = len - 1;
    	int num = 0;

    	while(s[i] == ' ') i--;

    	for(; i>=0; i--){
    		if(s[i] != 0){
    			num++;
    		}
    		else 
    			break;
    	}

    	return num;
        
    }
};