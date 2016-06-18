class Solution {
public:
    int calculate(string s) {
        int result;
        int size = (int)s.size();
        stack<int> nums;
        stack<char> opers;
        int l=0,r =0;
        
        for(int i = 0; i< size; i++){
            if(s[i] == '+'||s[i] == '-'||s[i] == '*'||s[i] == '/'){ // if operater
                int num2 = getnumber(l,r,s);
                nums.push(num2);
                if(!opers.empty()){
                    char op = opers.top();
                    
                    if(op == '*'||op == '/') { // if * /
                        opers.pop();
                        calnum(nums, op);
                        //  cout<<nums.top()<<endl;
                    }
                    if(!opers.empty() && (s[i] == '+' || s[i] == '-')){
                        calnum(nums, opers.top());
                        opers.pop();
                    }
                }
                opers.push(s[i]);
                l = i+1;
                r = i+1;
            }
            else r++;
        }
        
        int num = getnumber(l,r,s);
        nums.push(num);
        int osize = (int)opers.size();
        
        for(int i =0; i<osize; i++){
            char op = opers.top();
            opers.pop();
            calnum(nums, op);
        }
        result = nums.top();
        return result;
    }
    
    
    void calnum(stack<int>& nums, char op){
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        switch(op){
            case '+':
                nums.push(num1+num2);
                break;
            case '-':
                nums.push(num1-num2);
                break;
            case '*':
                nums.push(num1*num2);
                break;
            case '/':
                nums.push(num1/num2);
                break;
        }
        return;
    }
    
    int getnumber(int l, int r, string& s){
        int result = 0;
        for(int k= l; k <r ; k++){
            if(s[k] == ' ') continue;
            result = result*10 + (s[k] - '0');
        }
        return result;
    }
    
    
};