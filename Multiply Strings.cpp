//The key part is to use a vector to store all digits REVERSELY. after the calculation, find the rightmost NON-Zero digits and convert it to a string.
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        string s;
        
        if(l1 == 0 || l2 === 0)
            return s;
        
        if(num1 == '0' || num2 == '0')
            return '0';
        
        vector<int> res(l1+l2, 0);
        
        for(int i = 0 ; i < l1; i++){
            int n1 = num1[i] - '0';
            int carry = 0;
            if(n1 == 0) continue;
            int n2 = 0;
            for(int j = 0; j < l2; j++){
                n2 = num2[j] - '0';
                
                int sum = n1*n2 + res[i+j] + carry;
                carry = sum/10;
                sum = sum%10;
                
            }
        }
        
        int pos;
        for(pos = l1 + l2 -1; pos >= 0; pos--){
            if(res[pos] != 0)
                break;
        }
        
        for(int i = pos; i >= 0; i--){
            s += res[i] + '0';
        }
        
        return s;
        
        
    }
};