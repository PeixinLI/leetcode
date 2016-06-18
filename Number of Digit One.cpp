class Solution {
public:
    int countDigitOne(int n) {
    	if(n<=0) return 0;
    	int num = 0;
    	long long  temp = 10;   	
    	while(n >= temp/10){
    		
    		num += (n/temp)*(temp/10);
    		int a = (n/(temp/10))%10;//!!!n*10/temp != n/(temp/10)
    		if(a == 1) num += (n%(temp/10)) + 1;
    	  if(a > 1) num += temp/10;
    		temp = temp*10;
    		}
       return num;
    }
};