class Solution {
public:
    string convert(string s, int numRows) {
    	int size = s.size();
    	if(size == 0 || size == 1 || numRows == 1)
    		return s;

    	int i = 0;
    	while(i(n-1) < size){
    		res += s[i(n-1)];
    		i += 2;
    	}

    	for(int i = 1; i < numRows-1; i++){
    		int j = 0;
    		if(i < size){
    			res += s[j];
    			j += 2;
    			while(j(n-1) < size){
    				res += j(n-1)-i;
    				if(j(n-1) + i < size)
    					res += j(n-1) + i;
    				else 
    					break;
    			}
    		}
    	}

    	int i = 1;
    	while(i(n-1) < size){
    		res += s[i(n-1)];
    		i += 2;
    	}

    	return s;
        
    }
};