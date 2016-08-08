class Solution {
public:
    bool isPerfectSquare(int num){
    	if(num == 1)
    		return true;
    	int low = 1, high = num/2;

    	while(low <= high){
    		long mid = (long)(low + high)/2;
    		long t = mid * mid;

    		if(t == (long)num){
    			return true;
    		}
    		else if(t < (long)num){
    			low = mid + 1;
    		}
    		else{
    			high = mid -1;
    		}
    	}

    	return false;
        
    }
};