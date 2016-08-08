class Solution {
public:
    bool isPalindrome(string s) {
    	int size = s.size();

    	int i = 0;
    	int j = size -1;

    	while(i <= j){
    		if(i < 'A' || (i > 'Z' && i<'a') || i > 'z' ){
    			i++;
    		}
    		else if(j < 'A' || (j > 'Z' && j<'a') || j > 'z' ){
    			j--;
    		}
    		else {
    			if(s[i] != s[j] && s[i] - s[j] != 'A' - 'a' && s[j] - s[i] != 'A' - 'a' )
    				return false;
    			i++;
    			j--;
    		}
    	}

    	return true;
        
    }
};