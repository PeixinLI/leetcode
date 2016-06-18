class Solution {
public:
    void cal_num(stack<int>& nums, char op){
        int num2 = nums.top();
        nums.pop()
        int num1 = nums.top();
        nums.pop();
        switch (op) {
            case '+': nums.push(num1 + num2);return;
            case '-': nums.push(num1 - num2);return;
            case '*': nums.push(num1 * num2);return;
            case '/': nums.push(num1 / num2);return;
                
        }
    }
    
    int calculate(string s) {
        int size = s.size();
        stack<int> nums;
        stack<char> opers;
        int t; //
        
        for(int i = 0; i < size; i++){
            if(s[i] == '(') opers.push(s[i]);
            if(s[i] == '+' || s[i] == '-' || s[i] == ')' ){
               nums.push(t);
               t = 0;
               if (!opers.empty()){
                   char op = opers.top();
                   opers.pop();
                   else cal_num(nums, opers.top());
               }
               if(s[i] == ')') opers.pop();
               else opers.push(s[i]);
            }
            t += t*10 + s[i] - '0';
        }
        if(t != '') nums.push(t);
        while(!opers.empty()){
            cal_num(nums, opers.top());
            opers.pop();
        }
        return nums.top();
    }
};