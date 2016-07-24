// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0

// WHY ? Why time limit exceed ?

//i find that the begin+end will overflow and turn out to be a negative number, 
//when input n is very big. So I change start = begin + (end - begin)/2.

class Solution {
public:
    int guessNumber(int n) {
    	if(n == 1)
    		return 1;
    	int low = 1;
    	int high = n;
    	while(low <= high){
    		// int gssnum = (low + high)/2;
    		int gssnum = (high - low)/2 + low ///什么鬼
    		
    		int res = guess(gssnum); 
    		if(res == 1)
    			low = gssnum +1;
    		else if(res == -1)
    			high = gssnum - 1;
    		else
    			return gssnum;
    	}

    	return 0;      
    }
};