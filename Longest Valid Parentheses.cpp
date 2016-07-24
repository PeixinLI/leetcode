class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> stk;

		int size = s.size();

		for(int i = 0; i < size; i++){
		    cout<<i<<" ";
			if(s[i] == '('){
				stk.push(0);
				cout<<0<<endl;
			}
			else if(s[i] == ')'){
				stack<int> temp;
				int num = 0;
				while(!stk.empty() && stk.top() != 0 && stk.top() != -1){ // 0 denote "(" -1 denote ")"
					int t = stk.top();
					stk.pop();
					num += t;
				}
				cout<<num<<endl;
				if(!stk.empty() && stk.top() == 0){
					stk.pop();
					stk.push(num+2);
					cout<<num+2<<endl;
				}
				else {
					stk.push(num);
					stk.push(-1);
					cout<<num<<endl;
				}

			}
		}

		int max = 0;
		int num = 0;
		while(!stk.empty()){
			int t = stk.top();
			cout <<t <<endl;
			stk.pop();
			if(t == 0 || t == -1){
			    if(num > max)
			      max = num;
			    num = 0;
			}
			else
			num += t;
		}

		if(num > max) max = num;

		return max;
	}
};

//simpler method
//https://leetcode.com/discuss/7609/my-o-n-solution-using-a-stack
